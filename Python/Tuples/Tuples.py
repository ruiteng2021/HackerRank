if __name__ == '__main__':
    n = int(input())
    print (hash(tuple(map(int, input().strip().split(" ")))))

    n = int(input())
    integer_list = map(int, input().split())
    integer_list = [int(x) for x in integer_list]
    t = tuple(integer_list)
    print(hash(t))