if __name__ == '__main__':

    #l=[1,2,3,4,3,2,5,6,7]
    #indices = [i for i,val in enumerate(l) if val==3]
    nameList = []
    scoreList = []
    for _ in range(int(input())):
        name = input()
        score = float(input())

        nameList.append(name)
        scoreList.append(score)

    temp = scoreList.copy()
    temp.sort()
    temp = list(dict.fromkeys(temp))
    indices = [i for i,val in enumerate(scoreList) if val==temp[1]]
    #print (indices)
    result = []
    for i in range(len(indices)):
        result.append(nameList[indices[i]])

    result.sort()

    for i in range(len(result)):
        print(result[i])
    #print(result.sort())
"""
5
Harry
37.21
Berry
37.21
Tina
37.2
Akriti
41
Harsh
39

Compiler Message
Wrong Answer
Input (stdin)
Download
5
Harsh
20
Beria
20
Varun
19
Kakunami
19
Vikas
21
Expected Output
Download

Beria
Harsh



    """