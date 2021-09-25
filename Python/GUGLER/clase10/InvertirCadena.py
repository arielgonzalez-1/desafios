class InvertirCadena:
    def __init__(self, string):
        self.string = string
        self.index = len(string)

    def __iter__(self):
        return self

    def __next__(self):
        if self.index == 0:
            raise StopIteration
        self.index -= 1
        return self.string[self.index]