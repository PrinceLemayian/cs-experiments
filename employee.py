# Python Object-Oriented Programming example


class Employee:
    def __init__(self, name, base_salary):
        self.name = name  # Encapsulation of state
        self.base_salary = base_salary

    def calculate_salary(self):  # Abstraction
        return self.base_salary


class Manager(Employee):  # Inheritance
    def __init__(self, name, base_salary, bonus):
        super().__init__(name, base_salary)
        self.bonus = bonus

    def calculate_salary(self):  # Polymorphism (Method Overriding)
        return self.base_salary + self.bonus


# Creating objects and utilizing polymorphism
staff = [Employee("Alice", 50000), Manager("Bob", 60000, 10000)]

for employee in staff:
    print(f"{employee.name}'s salary is ${employee.calculate_salary()}")
