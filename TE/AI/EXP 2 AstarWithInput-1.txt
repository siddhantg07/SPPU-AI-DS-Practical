import copy

class Node:
    def __init__(self, data, level, fval):
        self.data = data
        self.level = level
        self.fval = fval
        self.parent = None  # To store the parent node

    def generate_child(self):
        x, y = self.find(self.data, '_')
        val_list = [[x, y - 1], [x, y + 1], [x - 1, y], [x + 1, y]]
        children = []
        for i in val_list:
            child = self.shuffle(self.data, x, y, i[0], i[1])
            if child is not None:
                child_node = Node(child, self.level + 1, 0)
                child_node.parent = self  # Set current node as parent
                children.append(child_node)
        return children

    def shuffle(self, data, x1, y1, x2, y2):
        if 0 <= x2 < len(data) and 0 <= y2 < len(data):
            temp_data = copy.deepcopy(data)
            temp = temp_data[x2][y2]
            temp_data[x2][y2] = temp_data[x1][y1]
            temp_data[x1][y1] = temp
            return temp_data
        else:
            return None

    def find(self, data, x):
        for i in range(len(data)):
            for j in range(len(data)):
                if data[i][j] == x:
                    return i, j

    def trace_path(self):
        path = []
        current_node = self
        while current_node is not None:
            path.append(current_node.data)
            current_node = current_node.parent
        path.reverse()
        return path

class Puzzle:
    def __init__(self, size):
        self.size = size
        self.open = []
        self.closed = []
        self.steps = 0  # To count steps

    def accept(self):
        puz = []
        print(f"Enter {self.size}x{self.size} puzzle matrix (use '_' for empty space):")
        for i in range(self.size):
            temp = input().split()
            puz.append(temp)
        return puz

    def f(self, start, goal):
        return self.h(start.data, goal) + start.level

    def h(self, start, goal):
        temp = 0
        for i in range(self.size):
            for j in range(self.size):
                if start[i][j] != goal[i][j] and start[i][j] != '_':
                    temp += 1
        return temp

    def process(self):
        print("Enter the start state matrix:")
        start = self.accept()
        print("Enter the goal state matrix:")
        goal = self.accept()

        start_node = Node(start, 0, 0)
        start_node.fval = self.f(start_node, goal)
        self.open.append(start_node)

        print("\n\n")

        while True:
            current_node = self.open[0]
            print("\n")
            for row in current_node.data:
                print(' '.join(row))
            if self.h(current_node.data, goal) == 0:
                print(f"Goal state reached in {self.steps} steps.")
                print("Path:")
                path = current_node.trace_path()
                for idx, state in enumerate(path):
                    print(f"Step {idx}:")
                    for row in state:
                        print(' '.join(row))
                break

            for child_node in current_node.generate_child():
                child_node.fval = self.f(child_node, goal)
                self.open.append(child_node)

            self.closed.append(current_node)
            del self.open[0]
            self.open.sort(key=lambda x: x.fval, reverse=False)
            self.steps += 1

puz = Puzzle(3)
puz.process()
