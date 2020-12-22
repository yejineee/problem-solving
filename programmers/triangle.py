import math

def find_L(a):
    L = 1
    for i in range(2, a+1):
        if a % i == 0:
            L = i
            break
    #print("%d of L is %d"%(a,L))
    return L

def solution(w,h):
    answer = 0 
    total = w*h
    block = 0 
    if(w == h):
        answer = total - w
    
    else:
        L = find_L(w)
        
        bound_w = L
        bound_h = math.floor(-h/w*L+h)
        for x in range(0,bound_w):
            if float(-h/w*x+h) - int(-h/w*x+h) != 0:
                block += 1
                #print("x : %d total block %d"%(x, block))
        for y in range(bound_h,h):
            if float(-w/h*y+w) - int(-w/h*y+w) != 0:
                block += 1
                #print("y : %d total block %d"%(y, block))
        block += 1
        block *= w/L
        
        answer = total - block
    
    #print(answer)
    return answer

solution(8,12)
