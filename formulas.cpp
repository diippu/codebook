/* ---------- POLYGON ----------
Area of polygon (shoelace):
Area = 0.5 * |sum(x[i]*y[i+1] - x[i+1]*y[i])|
Centroid of polygon:
Cx = sum((xi + xi+1) * cross(i,i+1)) / (6*Area)
Cy = sum((yi + yi+1) * cross(i,i+1)) / (6*Area)
Point inside polygon (ray casting):
Count intersections of ray to +x
Odd = inside, Even = outside
Convex polygon point inside:
For all edges (Pi, Pi+1):
cross(Pi+1-Pi, X-Pi) >= 0 (or <=0 consistently)
*/
/* ---------- REGULAR POLYGON ----------
n = number of sides, s = side length
PI = acos(-1.0)

Angles (in radians):
Sum of interior  = (n - 2) * PI
Single interior  = (n - 2) * PI / n
Central / Exterior = 2 * PI / n

Apothem (a) [Inradius - center to midpoint of side]:
a = s / (2 * tan(PI / n))

Circumradius (R) [Center to vertex]:
R = s / (2 * sin(PI / n))

Area formulas:
1. From side:  Area = (n * s * s) / (4 * tan(PI / n))
2. From R:     Area = 0.5 * n * R * R * sin(2 * PI / n)
3. From Apo:   Area = n * s * a * 0.5
*/
/* ---------- TRIANGLE ----------
Area using cross:
Area = |cross(B-A, C-A)| / 2
Circumcenter:
Intersection of perpendicular bisectors
(Omitted formula – compute via lines)
Incenter:
I = (a*A + b*B + c*C) / (a+b+c)
where:
Centroid:
G = (A+B+C)/3
Orthocenter:
H = A + B + C - 2*O (O = circumcenter)
Radius:
Inradius r = Area / s
Circumradius R = (a*b*c) / (4*Area)
Angle between vectors:
cos(theta) = dot(u,v)/(|u||v|)
*/

