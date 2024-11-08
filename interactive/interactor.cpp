// interactor.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sstream>
#include <bits/stdc++.h>

#define PIPE1 "/tmp/pipe1"  // solution to interactor
#define PIPE2 "/tmp/pipe2"  // interactor to solution
#define BUFFER_SIZE 1024

struct TestCase {
    int n;
    std::vector<int> parent;
};

bool isPathThroughRoot(const std::vector<int>& parent, int a, int b) {
    std::vector<bool> path_a(parent.size(), false);
    
    // Mark path from a to root
    int current = a;
    while (current != 0) {
        path_a[current] = true;
        current = parent[current];
    }
    path_a[0] = true;
    
    // Check path from b to root
    current = b;
    while (current != 0) {
        if (path_a[current]) return false;  // paths meet before root
        current = parent[current];
    }
    return true;  // paths only meet at root
}

std::vector<TestCase> readTestCases(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<TestCase> testcases;
    
    int t;
    file >> t;
    
    for (int i = 0; i < t; i++) {
        TestCase tc;
        file >> tc.n;
        tc.parent.resize(tc.n);
        tc.parent[0] = 0;  // root's parent is itself
        for (int j = 1; j < tc.n; j++) {
            file >> tc.parent[j];
        }
        testcases.push_back(tc);
    }
    
    return testcases;
}

bool validateSolution(const std::vector<int>& actual, const std::vector<int>& expected) {
    if (actual.size() != expected.size() - 1) return false;
    for (size_t i = 0; i < actual.size(); i++) {
        if (actual[i] != expected[i + 1]) return false;
    }
    return true;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    // Remove existing pipes if they exist
    unlink(PIPE1);
    unlink(PIPE2);
    
    // Create pipes
    if (mkfifo(PIPE1, 0666) == -1) {
        std::cerr << "Failed to create PIPE1" << std::endl;
        return 1;
    }
    if (mkfifo(PIPE2, 0666) == -1) {
        std::cerr << "Failed to create PIPE2" << std::endl;
        unlink(PIPE1);
        return 1;
    }

    // Read test cases
    std::vector<TestCase> testcases = readTestCases(argv[1]);
    std::cout << "Interactor: Read " << testcases.size() << " test cases" << std::endl;
    
    // First open write pipe
    std::cout << "Interactor: Opening write pipe..." << std::endl;
    int fd_write = open(PIPE2, O_WRONLY);
    if (fd_write < 0) {
        std::cerr << "Failed to open write pipe" << std::endl;
        return 1;
    }
    
    // Then open read pipe
    std::cout << "Interactor: Opening read pipe..." << std::endl;
    int fd_read = open(PIPE1, O_RDONLY);
    if (fd_read < 0) {
        std::cerr << "Failed to open read pipe" << std::endl;
        close(fd_write);
        return 1;
    }
    
    std::cout << "Interactor: Pipes opened successfully" << std::endl;
    
    // Send number of test cases
    std::string t_str = std::to_string(testcases.size()) + "\n";
    write(fd_write, t_str.c_str(), t_str.length());
    fsync(fd_write);  // Ensure write is complete
    
    std::cout << "Interactor: Sent number of test cases" << std::endl;
    
    for (const auto& test : testcases) {
        // Send N
        std::string n_str = std::to_string(test.n) + "\n";
        write(fd_write, n_str.c_str(), n_str.length());
        fsync(fd_write);
        
        std::cout << "Interactor: Sent N = " << test.n << std::endl;
        
        int queries = 0;
        const int MAX_QUERIES = 2 * test.n - 6;
        
        char buffer[BUFFER_SIZE];
        while (true) {
            // Read query from solution
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_read = read(fd_read, buffer, BUFFER_SIZE);
            
            if (bytes_read > 0) {
                std::string query(buffer);
                std::cout << "Interactor: Received query: " << query;
                
                std::istringstream iss(query);
                char type;
                iss >> type;
                
                if (type == '?') {
                    // Handle query
                    int a, b;
                    iss >> a >> b;
                    
                    if (queries >= MAX_QUERIES || a < 1 || a >= test.n || b < 1 || b >= test.n || a == b) {
                        std::string response = "-1\n";
                        write(fd_write, response.c_str(), response.length());
                        fsync(fd_write);
                        break;
                    }
                    
                    queries++;
                    int result = isPathThroughRoot(test.parent, a, b) ? 1 : 0;
                    std::string response = std::to_string(result) + "\n";
                    write(fd_write, response.c_str(), response.length());
                    fsync(fd_write);
                    
                    std::cout << "Interactor: Sent response: " << result << std::endl;
                }
                else if (type == '!') {
                    // Handle solution
                    std::vector<int> solution;
                    int p;
                    while (iss >> p) {
                        solution.push_back(p);
                    }
                    
                    if (!validateSolution(solution, test.parent)) {
                        std::cerr << "Wrong answer on test case " << test.n << std::endl;
                        return 1;
                    }
                    std::cout << "Interactor: Solution correct for test case" << std::endl;
                    break;
                }
            }
        }
    }
    
    // Cleanup
    close(fd_read);
    close(fd_write);
    unlink(PIPE1);
    unlink(PIPE2);
    
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}


