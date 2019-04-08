#控制参数：
 
nums = 41
call = 3
 
#参数定义：
peoples = []
for _ in range(nums):
    peoples.append(True)
 
result = []
num =1
#主逻辑
#any 函数的用法，判断里面是否全为False，全是False则返回False，只要有一个True
while(any(peoples)):
    for index,people in enumerate(peoples):
        if people:
            if num == call:
                peoples[index] = False
                result.append(index+1)
	            # print(index+1)#每轮的出局者                
	            # print(peoples)#每次的队列状态
                num = 1               
            else:
                num += 1
print('-'* 25)
print('\n总数为%d,报数为%d' % (nums,call))        
print('约瑟夫序列为：\n%s\n' % result)      
print('-'* 25)
