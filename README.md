<p align="center">
  <a href="https://github.com/1nfocalypse/Autonomous-Vehicle-Controller">
	<img alt="AV-Controller" src="https://i.imgur.com/o4so5MG.png"/>
  </a>
</p>
<h2 align="center">Autonomous Vehicle Controller</h3>
<h3 align="center">
  Predictive Velocity Modelling and Control in Autonomous Vehicles
</h2>
<p align="center">
  By <a href="https://github.com/1nfocalypse">1nfocalypse</a>, <a href="https://github.com/marystirling">marystirling</a>, <a href="https://github.com/jroge">jroge</a>, and Ryan
</p>


## Predictive Velocity Modelling and Control
This project is focused on utilizing an open loop system to allow for arbitrary speed input in autonomous vehicles. This is accomplished by processing the entered value, then generating an approximate Sigmoid function
via a mesh and natural cubic spline interpolation. From this point, a numerical derivative is taken to yield a smooth acceleration or deceleration to the desired speed, which is iteratively fed to the vehicle. Once this speed is 
achieved, differences and deviations from it will generate their own microadjustments, allowing the controller to also function as a form of cruise control. 

While solidly in a fledgeling phase, the project demonstrates promise to allow for automated speed changes based on environment context, i.e. automatically adapting speed based on speed limits. Further changes needed include an error
correction to account for externalities, such as wind resistance and friction, along with safety implementations.

## Goals
- Obtain user desired speed
- Generate a mesh of data points approximating a Sigmoid curve to yield a smooth velocity change
- Interpolate these points, and obtain a numerical derivative to find an acceleration value
- Input the acceleration value into the vehicle, accelerating or decelerating as required

## Applications
The intended application of this project is to serve as a basis for adaptive speed changes based on contextual environment, and to serve in the larger task of efficient routing. Traffic is a major field of research, and autonomous 
vehicles present a unique possible solution to many problems that arise from human drivers. One stipulation of this, however, is consistent speed. By being able to define a certain speed based on the context of an area, one would be able
to help mitigate traffic buildup as a result of speed differences as commonly observed on highways. While currently inadequate, this controller serves as a basis for this task by being able to accept arbitrary input and generate both a 
feasible and meaningful path to a target speed, then hold it, in a manner that avoids extreme acceleration that would likely be harsh on the users.

## Paper
The redacted paper for this project can be found [here](Pred-Velo-Mdl-Ctrl-AVs-REDACTED-1-1-1.pdf). An unredacted copy can be made available on request. Contact information for such requests can be found on my website, as linked on
my profile.

## Further Problems
Further points of interest include the utilization of an error correction function to account for things such as friction and wind resistance. A major point of focus will be in the inclusion of safety mechanisms, as this controller offers
none at the moment. Potential sources for these include adaptive cruise control designs. Another point of interest is providing a means of abstracting roads, then utilizing this abstraction to allow for efficient routing and pathfinding,
with the speed of the vehicle being automated to help aid in traffic mitigation along these paths. 
