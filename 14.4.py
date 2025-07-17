import numpy as np
arr11=5-np.arange(1,13).reshape(4,3)
a=np.sum(arr11)               #计算所有元素的和
b=np.sum(arr11,axis=0)         #对每一列元素求和
c=np.sum(arr11, axis=1)        #对每一行元素求和
d=np.cumsum(arr11)           #对每一个元素求累计和
e=np.cumsum(arr11, axis=0)     #计算每一列的累计和
f=np.cumprod(arr11, axis=1)     #计算每一行的累计积
g=np.min(arr11)               #计算所有元素的最小值
h=np.max(arr11, axis=0)        #计算每一列的最大值
i=np.mean(arr11)              #计算所有元素的均值
j=np.mean(arr11, axis=1)        #计算每一行的均值
k=np.median(arr11)            #计算所有元素的中位数
l=np.median(arr11, axis=0)      #计算每一列的中位数
m=np.var(arr11)               #计算所有元素的方差
n=np.std(arr11, axis=1)         #计算每一行的标准差
print("\n",a,"\n",b,"\n",c,"\n",d,"\n",e,"\n",f,"\n",g,"\n",h,"\n",i,"\n",j,"\n",k,"\n",l,"\n",m,"\n",n)