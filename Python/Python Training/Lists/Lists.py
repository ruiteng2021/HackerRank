if __name__ == '__main__':
    N = int(input())
    result = []
    lines = []
    for i in range(N):
        lines.append(input())
    for i in range(N):
        if(lines[i].find("insert") != -1):
            temp = lines[i].split(" ")
            result.insert(int(temp[1]), int(temp[2]))
        if(lines[i].find("print") != -1):
            print(result)
        if(lines[i].find("remove") != -1):
            temp = lines[i].split(" ")
            result.remove(int(temp[1]))
        if(lines[i].find("append") != -1):
            temp = lines[i].split(" ")
            result.append(int(temp[1]))
        if(lines[i].find("sort") != -1):
            result.sort()
        if(lines[i].find("pop") != -1):
            temp = lines[i].split(" ")
            result.pop()
        if(lines[i].find("reverse") != -1):
            result.reverse()

"""
4
append 1
append 2
insert 3 1
print

"""