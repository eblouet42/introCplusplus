from time import time

def timeTest(size):
    print("Pour un tableau de ",size,"eléments, en Python...")
    t0=time()
    tab=[]
    for i in range(size):
        tab.append(2*i)
    t1=time()
    print("Da tableau crée en ",int((t1-t0)*(1000000000))/1000,"μs")
    t0=time()
    somme=0
    for i in tab:
        somme+=i
    t1=time()
    print( "Da somme faite en ",int((t1-t0)*(1000000000))/1000,"μs, et elle vaut ",somme)
    t0=time()
    X=sum(tab)
    t1=time()
    print("Avec la fonction sum(), da somme faite en ",int((t1-t0)*(1000000000))/1000,"μs, et elle vaut ",X,"\n")

if __name__ == "__main__":
    timeTest(1000)
    timeTest(10000)
    timeTest(100000)
    timeTest(1000000)
    
    # La fonction sum() est plus sensiblement plus rapide que le calcul manuel
    # mais cela reste bien plus lent que sur C++ (création & somme)