class math:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    def add(self):
        return self.a + self.b
    def sub(self):
        return self.a - self.b
    def mul(self):
        return self.a * self.b
    def div(self):
        return self.a / self.b

while 1:
    a = int(input("Kuy tin: "))
    b = int(input("Kuy tin2: "))
    print(math(a, b).add())
    print(math(a, b).sub())
    print(math(a, b).mul())
    print(math(a, b).div())