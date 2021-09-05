# DSP HW2
<center> <font size=2> Jason < 2020/11 > </font> </center>

original hackmd : https://hackmd.io/@jasonho610/SJBNyLOLD
## Problem
![](https://i.imgur.com/SxwyHZu.png)
More details in DSP-HW2.docx

## Hand-written Questions
### Q1.
If $x(t)=e^{j\Omega t}$, find $y(t)$. Note that $y(t)$ can be expressed by $y(t)=H(\Omega)e^{j\Omega t}$, where $H(\Omega)$ is a funtion of $\Omega$ with parameters of $R$ and $C$. If you can find $H(\Omega)$, you find the solution of $y(t)$ of $x(t)=e^{j\Omega t}$.

### A1.
The Eq.(3) depicted in background

$$x(t)=RC\frac{\mathrm{d}y(t)}{\mathrm{d}t}+y(t)$$
can help finding $H(t)$. We can multiply a $\mathrm{d}t$, which becomes

$$x(t)\mathrm{d}t = RC\mathrm{d}y+y(t)\mathrm{d}t$$
then integrate the whole equation, which gives

$$\int_{}^{} x(t)\mathrm{d}t=\int_{}^{}RC\mathrm{d}y+\int_{}^{}y(t)\mathrm{d}t$$

Using the Note on question description, where $y(t)$ can be expressed by $y(t)=H(\Omega)e^{j\Omega t}$, we then substitude $x(t)$ with $e^{j\Omega t}$, $y(t)$ with $H(\Omega)e^{j\Omega t}$

$$\begin{eqnarray}
&\int_{}^{} e^{j\Omega t}\mathrm{d}t&=\int_{}^{}RC\mathrm{d}y+\int_{}^{}H(\Omega)e^{j\Omega t}\mathrm{d}t
\\ 
\Rightarrow\ &\frac{1}{j\Omega}e^{j\Omega t}&=RCy(t)+\frac{1}{j\Omega}H(\Omega)e^{j\Omega t}
\\
\Rightarrow\ &\frac{1}{j\Omega}e^{j\Omega t}&=RCH(\Omega)e^{j\Omega t}+\frac{1}{j\Omega}H(\Omega)e^{j\Omega t}
\\
\Rightarrow\ &\frac{1}{j\Omega}&=RCH(\Omega)+\frac{1}{j\Omega}H(\Omega)
\\
\Rightarrow\ &1&=j\Omega RCH(\Omega)+H(\Omega)\end{eqnarray}
$$

Our intention is to get $H(\Omega)$, so we rewrite the equation to

$$\begin{eqnarray}
&H(\Omega)+j\Omega RCH(\Omega)=1
\\
\Rightarrow\ &H(\Omega)(1+j\Omega RC)=1
\\
\Rightarrow\ &H(\Omega)=\frac{1}{1+j\Omega RC}\end{eqnarray}$$

As result, we find out $H(\Omega)$, implying that the solution is

$$\begin{eqnarray}
y(t)&=&H(\Omega)e^{j\Omega t}
\\
&=&\frac{e^{j\Omega t}}{1+j\Omega RC}\end{eqnarray}$$

### Q2.
If $x(t)=e^{j\Omega t}$, $R=1000\Omega$, $C=(\frac{1}{2\pi}*\frac{1}{2\pi}*\frac{1}{400}*\frac{1}{400}*\frac{1}{1000})F$; find $y(t)$ for $\Omega=2\pi*f$ and $f=100Hz, 400Hz, 3000Hz$.

### A2.
1. for $f=100Hz$

$$\begin{eqnarray}
y(t)&=&\frac{e^{j\Omega t}}{1+j\Omega RC}
\\
&=&\frac{e^{j(2\pi f)t}}{1+j(2\pi f)RC}
\\
&=&\frac{e^{j(200\pi )t}}{1+j(200\pi )1000*\frac{1}{2\pi}*\frac{1}{2\pi}*\frac{1}{400}*\frac{1}{400}*\frac{1}{1000}}
\\
&=&\frac{e^{j(200\pi )t}}{1+\frac{j}{3200\pi }}
\end{eqnarray}$$

2. for $f=400Hz$

$$\begin{eqnarray}
y(t)&=&\frac{e^{j\Omega t}}{1+j\Omega RC}
\\
&=&\frac{e^{j(2\pi f)t}}{1+j(2\pi f)RC}
\\
&=&\frac{e^{j(800\pi )t}}{1+j(800\pi )1000*\frac{1}{2\pi}*\frac{1}{2\pi}*\frac{1}{400}*\frac{1}{400}*\frac{1}{1000}}
\\
&=&\frac{e^{j(800\pi )t}}{1+\frac{j}{800\pi }}
\end{eqnarray}$$

3. for $f=3000Hz$

$$\begin{eqnarray}
y(t)&=&\frac{e^{j\Omega t}}{1+j\Omega RC}
\\
&=&\frac{e^{j(2\pi f)t}}{1+j(2\pi f)RC}
\\
&=&\frac{e^{j(6000\pi )t}}{1+j(6000\pi )1000*\frac{1}{2\pi}*\frac{1}{2\pi}*\frac{1}{400}*\frac{1}{400}*\frac{1}{1000}}
\\
&=&\frac{e^{j(6000\pi )t}}{1+\frac{3j}{320\pi }}
\end{eqnarray}$$

## Code-written Demonstration

Simulate by C++ programs for the Q2 with $\tau=\frac{1}{800}sec, \frac{1}{4000}sec, \frac{1}{16000}sec$.

### 1. Libraries
```cpp=
#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
```
- <vector>
Vectors in C++ are the dynamic arrays that are used to store data. Unlike arrays, which are used to store sequential data and are static in nature, Vectors provide more flexibility to the program. Vectors can resize itself automatically when an element is inserted or deleted depending on the need of the task to be executed. 

- <complex>
The functions and operators pertaining to complex numbers are implemented by means of class complex and are contained in the C++ complex number mathematics library. The definition of class complex overloads the standard input, output, arithmetic, comparison, and assignment operators of C++, as well as the standard names of the exponential, logarithm, power, square root, and trigonometric functions (sine, cosine, hyperbolic sine, and hyperbolic cosine). As a results, we don't need to rewrite a new structure.

- <iomaip>
It's the standard library used for layouting outputs.

### 2. Declaration
```cpp=
int freq[3] = {100, 400, 3000};
int sample[3] = {8000, 4000, 16000};
int R = 1000;
float pi = acos(-1);
float C = 1/(2*pi*2*pi*400*400*1000);
vector<complex<float>> x_n, y_n, y_t, diff;
float sqr_err = 0;
```
- x_n, y_n, y_t, diff refers to $x[n]$, $y[n]$, $y(t)$, $y[n]-y(t)$ respectively. 

### 3. Producing Discrete Signal: x[n]
```cpp=
float tau = (float)1/sample[j];
for(int k=0;k<sample[j];k++)    // Assume that signals are all within 1 sec.
{
    float t = tau*k;
    complex<float> c(0, 2*pi*freq[i]*t);
    complex<float> sig = exp(c);      // Assume that max votage of x_n is 1V.
    x_n.push_back(sig);
}
```
### 4. Calculating Discrete Output: y[n]
```cpp=
complex<float> c(1,0);     // Initial votage of y_n is 1V. => cus |y(t)| -> 0, when t = 0.
y_n.push_back(c);
for(int k=1;k<sample[j];k++)    // Assume that signals are all within 1 sec.
{
    complex<float> output;
    output = ((complex<float>)(R*C/(R*C+tau))*y_n[k-1]) + ((complex<float>)(tau/(tau+R*C))*x_n[k]);
    y_n.push_back(output);
}
```
- We use the the Eq.(8) depicted in background

$$y[n]=\frac{RC}{RC+\tau}y[n-1]+\frac{\tau}{\tau +RC}x[n]$$

to derive y[n].

### 5. Calculating the Difference and Square Error between y(t) and y[n]
```cpp=
float sqr_err = 0;
for(int k=0;k<sample[j];k++)    // Calculate y_t, the difference between y_n & y_t, and the square error.
{
    float t = tau*k;
    complex<float> output;
    complex<float> c1(0, 2*pi*freq[i]*t);
    c1 = exp(c1);     // c1 = e^(jwt)
    complex<float> c2(0, 2*pi*freq[i]*R*C);
    complex<float> H = (complex<float>)1/((complex<float>)1+c2);
    output = (complex<float>)(H*c1);

    y_t.push_back(output);
    diff.push_back(output-y_n[k]);
    sqr_err = sqr_err + pow(abs(diff[k]),2);
}
```
### 6. Writting Results to Text File
```cpp=
cout.precision(5);    // set the precision (decimal point) to 5
            
ofstream myfile;
string filename = to_string(freq[i]) + "Hz_" + to_string(sample[j]) + "Hz_Voltage_Output.txt";
cout << filename << endl;
myfile.open(filename, ios::out);
if(!myfile)
{
    cout << "Can't open file" << endl;
    return 1;
}

myfile << "Iteration n, Sampletime t (sec), Signal x[n] (real, img), Output y[n] (real, img), Actual_Output y(t) (real, img), Difference y(t)-y[n] (real, img)" << endl << endl;
myfile << "Square Error : " << sqr_err << endl << endl;

for(int k=0;k<sample[j];k++)    // layout
{
    float t = tau*k;
    myfile << "n: " << setw(4) << k;
    myfile << ", t: " << setw(8) << fixed << t;
    myfile << ", x[n]: " << setw(21) << x_n[k];
    myfile << ", y[n]: " << setw(21) << y_n[k];
    myfile << ", y(t): " << setw(21) << y_t[k];
    myfile << ", diff: " << setw(21) << diff[k] << endl;
}

myfile.close();
```
### 6. Results
- 9 text file

![](https://i.imgur.com/i9boHpO.png)
- content

![](https://i.imgur.com/UH4WwjC.png)

![](https://i.imgur.com/7mHLvbD.png)

![](https://i.imgur.com/kybXkQY.png)


## Discussion
### 1. Steady State & Transient State
Practically, We can deem that the Eq.(3) depicted in background is a 1st order differential equation

$$\begin{eqnarray}
x(t)=RC\frac{\mathrm{d}y(t)}{\mathrm{d}t}+y(t)
\\
\Rightarrow e^{j\Omega t}= RC\frac{\mathrm{d}y(t)}{\mathrm{d}t}+y(t)
\end{eqnarray}$$

and find out what exactly $y(t)$ is with relevant techniques. First, we assume that particular solution $y_p=Be^{j\Omega t}$, where $B$ is a constant, and inserting it into the equation above gives

$$\begin{eqnarray}
&e^{j\Omega t}&=&RC\frac{\mathrm{d}y_p(t)}{\mathrm{d}t}+y_p(t)
\\
\Rightarrow \ &e^{j\Omega t}&=&j\Omega RC\cdot Be^{j\Omega t}+Be^{j\Omega t}
\\
\Rightarrow \ &1&=&j\Omega RC\cdot B+B
\\
\Rightarrow \ &1&=&(j\Omega RC+1)B
\\
\Rightarrow \ &B&=&\frac{1}{j\Omega RC+1}
\end{eqnarray}$$

The particular solution is derived, $y_p(t)=\frac{e^{j\Omega t}}{j\Omega RC+1}$. Second, we can derive the homogenous solution $y_h$ by

$$\begin{eqnarray}
&RC\frac{\mathrm{d}y_h(t)}{\mathrm{d}t}+y_h(t)=0
\\
\Rightarrow &\frac{\mathrm{d}y_h}{\mathrm{d}t}=-\frac{y_h}{RC}
\\
\Rightarrow &\frac{\mathrm{d}y_h}{y_h}=-\frac{\mathrm{d}t}{RC}
\\
\Rightarrow &\int\frac{\mathrm{d}y_h}{y_h}=-\int\frac{\mathrm{d}t}{RC}
\\
\Rightarrow &ln{(y_h)} = -\frac{t}{RC}+c
\\
\Rightarrow &y_h = e^{\frac{-t}{RC}+c}
\\
\Rightarrow &\ y_h = A\cdot e^{\frac{-t}{RC}},\ where\ A\ is\ a\ constant
\end{eqnarray}$$

Third, we utilize two conditions: $\begin{cases} y(t)=y_h(t)+y_p(t)\\y(0)=0\end{cases}$ to find $A$, and $y(t)$ eventually.

$$\begin{eqnarray}
&y(t)=y_h(t)+y_p(t)=A\cdot e^{\frac{-t}{RC}}+\frac{e^{j\Omega t}}{j\Omega RC+1}
\\
\Rightarrow &y(0)=A+\frac{1}{j\Omega RC+1}=0
\\
\Rightarrow &A=-\frac{1}{j\Omega RC+1}
\\
\Rightarrow &y(t)=-\frac{e^{\frac{-t}{RC}}}{j\Omega RC+1}+\frac{e^{j\Omega t}}{j\Omega RC+1}
\end{eqnarray}$$

When $t$ gets bigger, $e^{\frac{-t}{RC}}$ approach to $0$ by a exponential speed.

>The solution of the differential equation of most physical systems is in two parts. The transient solution or natural response is that part of the total response that approaches zero as time approaches infinity, while the steady-state solution or forced response is that part of the total response that does not approach zero as time approaches infinity.

So, we can know that $y_p=\frac{e^{j\Omega t}}{j\Omega RC+1}$ is the function that describes steady state; in the other hand, $y_h=-\frac{e^{\frac{-t}{RC}}}{j\Omega RC+1}$ is the one describing transient state.

- Check answers with python implementation.
```python=
from sympy import *
R, C = symbols('R C', real=True, positive=True)
Omg = symbols('Omega', real=True)
t = symbols('t', real=True)
f = symbols('f', real=True)
y = Function('y')
s, Y = symbols('s Y')
l = R*C*Derivative(y(t), t)+y(t)
x = exp(I*Omg*t)
ode = Eq(l,x)
ode
answer = dsolve(ode, y(t), ics={y(0):0})
answer
```
**ode:**
![](https://i.imgur.com/igbsPmu.png)
**answer:**
![](https://i.imgur.com/QcHZIJC.png)


Rewriting $y(t)$ to our equation terms and simplifing the fraction are as follows:

$$\begin{eqnarray}
y(t)&=&\left(
\frac{(-jRC\Omega -1)e^{j\Omega t}e^{\frac{t}{RC}}}{(RC\Omega)^2-2jRC\Omega -1}
+
\frac{jRC\Omega +1}{(RC\Omega)^2-2jRC\Omega -1}\right)e^{-\frac{t}{RC}}
\\
&=&\left(\frac{(jRC\Omega +1)e^{j\Omega t}e^{\frac{t}{RC}}}{-(RC\Omega)^2+2jRC\Omega +1}
+
\frac{-(jRC\Omega +1)}{-(RC\Omega)^2+2jRC\Omega +1}\right)e^{-\frac{t}{RC}}
\\
&=&\left(\frac{(jRC\Omega +1)e^{j\Omega t}e^{\frac{t}{RC}}}{(jRC\Omega)^2+2jRC\Omega +1}
-\frac{jRC\Omega +1}{(jRC\Omega)^2+2jRC\Omega +1}\right)e^{-\frac{t}{RC}}
\\
&=&\left(\frac{(jRC\Omega +1)e^{j\Omega t}e^{\frac{t}{RC}}}{(jRC\Omega +1)^2}
-\frac{jRC\Omega +1}{(jRC\Omega +1)^2}\right)e^{-\frac{t}{RC}}
\\
&=&\left(\frac{e^{j\Omega t}e^{\frac{t}{RC}}}{jRC\Omega +1}
-\frac{1}{jRC\Omega +1}\right)e^{-\frac{t}{RC}}
\\
&=&\frac{e^{j\Omega t}}{jRC\Omega +1}
-\frac{e^{-\frac{t}{RC}}}{jRC\Omega +1}
\\
&=&y_p(t)+y_h(t)
\end{eqnarray}$$


### 2. Undersampling
When our sample rate is less than the **Nyquist rate**, we say we're undersampling and **aliasing** will yield misleading results. This kind of undesired outcome may be observed in **3000Hz_4000Hz_Voltage_Output.txt** .

**Nyquist Rate:**
> In signal processing, the Nyquist rate specifies a sampling rate. In units of samples per second its value is twice the highest frequency (bandwidth) in Hz of a function or signal to be sampled. With an equal or higher sampling rate, the resulting discrete-time sequence is said to be free of the distortion known as aliasing. 

**Alias Effect:**
> In signal processing and related disciplines, aliasing is an effect that causes different signals to become indistinguishable (or aliases of one another) when sampled.

But in pratical world, twice may not be enough. We can see the failed results in **3000Hz_8000Hz_Voltage_Output.txt**, where its squared errors is **0.0719836**.
I reckon this consequence is due to the limitation of computing precisions; in another words, if we can make every computation preciser, for example, turning datatype "float" to "double", the results may improve to some degree.

### 3. Data Type Error
There are plenty of places that needs to convert data type into the compatible one, in order to get correct and accurate results. This is something that certainly have to be cautious for.
In my cpp code, I use Explicit Type Conversion a lot to make sure that all calculation is stored and computed in the right way.
>Explicit Type Conversion: This process is also called type casting and it is user-defined. Here the user can typecast the result to make it of a particular data type.
Syntax:
```(type) expression```

### 4. Proof
- Why can $y(t)$ be expressed as $y(t)=H(\Omega)e^{j\Omega t}$ ?

We understand that RC circuit is a LTI system; hence, we can represent the system by convolution

$$\begin{eqnarray}
y[n]&=&x[n]*h[n]
\\
&=&\sum_{k=-\infty }^{\infty }x[k]h[n-k]
\\
&=&\sum_{k=-\infty }^{\infty }x[n-k]h[k]
\\
&=&\sum_{k=-\infty }^{\infty }h[k]\cdot e^{j\Omega (n-k)}
\\
&=&\left( \sum_{k=-\infty }^{\infty }h[k]e^{-j\Omega k}\right) e^{j\Omega n},\ where\ k\ is\ a\ dummy\ variable\
\\
&=&H(\Omega )e^{j\Omega n}
\end{eqnarray}$$

### 5. A Little Question for Teacher (QAQ
在解出 $y_h$ 的時候，我們是從積分去得到 $ln{(y_h)} = -\frac{t}{RC}+c$ ，其中 $c$ 應該要是real constant，因此回到 $y_h = A\cdot e^{\frac{-t}{RC}}$ 的時候，$A=e^{c}$ 也應該要是real number才對。但為何最後解答會是complex number？
我認為找解的process沒有錯，但這個地方應該有更好的寫法，才不會造成這樣怪怪。（雖然這可能是工程數學的範疇，但我實在找不到原因，因為以前教的時候輸入都是實數，像是$cos(x)$、$e^x$之類的，而非 $e^{j\Omega t}$ 這種，希望老師可以替我解答。）