Hyperparameter tuning
-----
The hyperparameters were tuned mostly by manual tuning, as described below when explaining the effect of each one of the PID components. I tried
using both twiddle and gradient descent, but I didn't get the parameters to converge to any useful values. The code for the twiddle implementation is contained in the 'twiddle' branch.

Effect of PID components
-----

The 'P' component, makes the car react to the CTE value in a linear fashion, this in fact allows the car to get close to the CTE=0 line but there is an oscillation around it. For example with a (large) value of 1.0:

[![SDC - PID controller p=1 ](https://img.youtube.com/vi/fSk1eqMjANo/0.jpg)](https://www.youtube.com/watch?v=fSk1eqMjANo)


This is less dramatic for smaller values of 'Kp', but whenever the car encounters a corner, the CTE increases faster and this inducees a violent steering correction which often results in the car going off track. An example is shown below with Kp=0.1:

[![SDC - PID controller p=1 ](https://img.youtube.com/vi/e2-nBJlYhYk/0.jpg)](https://www.youtube.com/watch?v=e2-nBJlYhYk)

With Kp(i.e. 0.001) of a smaller value, the car just doesn't react fast enough, the oscillations around the center line seem to have a very low frequency:

[![SDC - PID controller p=1 ](https://img.youtube.com/vi/6k-7NZSEtFI/0.jpg)](https://www.youtube.com/watch?v=6k-7NZSEtFI)

Taking all of this into account, 0.1 seems to be a good start value for Kp.

The 'D' component dampens(as expected) the oscillations induced by the 'P' component. It seems like a good start value for it is 1.0, with this value(and Kp=0.1), the car is able to circulate around the whole track.

[![SDC - PID controller p=1 ](https://img.youtube.com/vi/jZ_QEb-vRCc/0.jpg)](https://www.youtube.com/watch?v=jZ_QEb-vRCc)

The 'I' component, meanwhile, is meant to adjust for bias in the control, for example when the alignment of the car isn't correctly done so the wheels aren't pointing straight when the steering input is zero. There seems to be no bias in the project, which means no value of 'Ki' is required. 


Simulating bias
-----

Bias can be simulated by adding a constant value to the input steering angle. When doing this by substracting a constant 0.3 from the steering value, this is what the behavior of the car looks like:

[![SDC - PID controller p=1 ](https://img.youtube.com/vi/7O_K_s_Lp9g/.jpg)](https://www.youtube.com/watch?v=7O_K_s_Lp9g)

When setting Ki to 0.001, this bias is corrected(after some initial oscillation), so that the car is also able to pass the track:

// VIDEO corrected bias
[![SDC - PID controller p=1 ](https://img.youtube.com/vi/-Dhbz7xCcqo/.jpg)](https://www.youtube.com/watch?v=-Dhbz7xCcqo)
