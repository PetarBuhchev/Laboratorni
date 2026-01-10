class Person:
    def __init__(self,name, lastname, age, nationality):
        self.name = name
        self.lastname = lastname
        self.age = age
        self.nationality = nationality
    def print_info(self):
        print(self.name, self.lastname, self.nationality)

class Student(Person):
    def __init__(self,name, lastname, age, nationality,university, year_of_study, fn):
        super().__init__(name, lastname, age, nationality)
        self.university = university
        self.year_of_study = year_of_study
        self.fn = fn
    def print_info(self):
        print(self.name, self.lastname, self.nationality, self.university, self.year_of_study)

class Lector(Person):
    ##Нови полета университет и опит, предефинирай printinfo - инфото за новите полета и два обекта от този клас
    def __init__(self, name, lastname, age, nationality, university, experience, students):
        super().__init__(name, lastname, age, nationality)
        self.university = university
        self.experience = experience
        self.students = students

    def print_info(self):
        print(self.name, self.lastname, self.nationality, self.university, self.experience)
        print(self.students)

    def create_student(self, fn):
        self.students[fn] = 0
    def set_grade(self, fn, grade):
        self.students[fn] = grade
    def avrg_grade(self):
        count_grade = 0
        count_student = 0
        for student in self.students.values():
            count_grade += student
            count_student += 1
        return count_grade / count_student
##Добавя се към кода в класа лектор - речник, в който ключа е фак.номер на студент, а стойност е оценка на студент
##в класа студент се добавя фак. номер, в класа лектор се добавя нов метод, метода добавя студент с ключ фак.номер и стойност 0
##във класа лектор се добавя set_grade в който по фак.номер се поставя оценка на студента
##да се предефинира printinfo, така че да принтира студентите на преподавателя с техните оценки
##добавете към класа лектор нов метод, който изчислява средния успех на студентите на преподавателя
person1 = Person('John', 'Doe', 19, 'English')
person2 = Person('Petar', 'Ivanov', 20, 'Bulgarian')
person3 = Person('John', 'Smith', 35, 'Hungarian')
person1.print_info()
person2.print_info()
person3.print_info()
student1 = Student(person1.name, person1.lastname, person1.age, person1.nationality,'TU', 2012,839408230)
student1.print_info()
student2 = Student(person2.name, person2.lastname, person2.age, person2.nationality,'SU', 2025, 458439589)
student2.print_info()
lector1 = Lector(person3.name, person3.lastname, person3.age, person3.nationality, 'Bulgarian', 20, students={123213:10})
lector2 = Lector('Ivan', 'Ivanov', 50, 'Spanish', 'PU', 10, students={123213123:1})
lector1.print_info()
lector2.print_info()
lector1.create_student(121225001)
lector1.set_grade(121225001, 100)
lector1.print_info()
print(lector2.avrg_grade())