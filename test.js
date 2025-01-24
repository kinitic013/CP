// Array of skills to iterate through
const skills = [
  "C/C++",
  "HTML",
  "CSS",
  "JavaScript",
  "PHP",
  "jQuery",
  "EJS",
  "Node.js",
  "Express.js",
  "MongoDB",
  "PostGres",
  "ElasticSearch",
  "AWS Opensearch",
  "Bootstrap",
  "React.js",
  "Redux",
  "MySQL",
  "Git",
  "GitHub",
  "Docker",
  "Linux",
  "Postman",
  "Python",
  "Django",
  "Selenium",
  "MATLAB",
  "Teamwork",
  "Public Speaking",
  "Leadership"
];

// Delay function
function delay(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

// Function to input skills into the search bar and simulate pressing Enter
async function inputSkills() {
  const searchInput = document.querySelector('#input-281'); // Updated input element selector
  
  if (!searchInput) {
    console.error("Search input not found");
    return;
  }

  for (const skill of skills) {
    // Focus the search bar
    searchInput.focus();

    // Input the skill
    searchInput.value = skill;

    // Trigger an input event to simulate typing
    searchInput.dispatchEvent(new Event('input', { bubbles: true }));

    // Wait briefly before simulating Enter
    await delay(500);

    // Simulate pressing Enter
    const event = new KeyboardEvent('keydown', {
      key: 'Enter',
      code: 'Enter',
      which: 13,
      keyCode: 13,
    });
    searchInput.dispatchEvent(event);

    // Wait before inputting the next skill
    await delay(1000);
  }
}

// Run the script
inputSkills();
