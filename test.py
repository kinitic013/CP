employees = [
    {
        "id": 1,
        "name": "Alice",
        "department": "Engineering",
        "skills": ["Python", "JavaScript", "SQL"],
        "experience": 5
    },
    {
        "id": 2,
        "name": "Bob",
        "department": "Marketing",
        "skills": ["SEO", "Content Writing", "Data Analysis"],
        "experience": 3
    }]

for i in range(0,len(employees)):
    if(i['department'] == "Engineering"):
        print(i['name'])
        for j in range(0,len(i["skills"])):
            print(j)