#include <iostream>
#include <vector>
using namespace std;

struct Point {
   double x, y, z;
};

struct Particle {
   Point p,v;
   double m;
};

// Pre:
// Post: returns the sum of p1 and p2.
Point sum(Point p1, Point p2) {
   Point r;
   r.x = p1.x + p2.x;
   r.y = p1.y + p2.y;
   r.z = p1.z + p2.z;
   return r;
}

// Pre:
// Post: returns a times p.
Point mul(double a, Point p) {
   Point r;
   r.x = a*p.x;
   r.y = a*p.y;
   r.z = a*p.z;
   return r;
}

// Pre:
// Post: returns p/a.
Point div(double a, Point p) {
   Point r;
   r.x = p.x/a;
   r.y = p.y/a;
   r.z = p.z/a;
   return r;
}

void printDouble(double d) {
   if (abs(d) < 1e-7) cout << 0.0;
   else cout << d;
}

// Pre:
// Post: prints the give point
void printPoint(Point point) {
   printDouble(point.x);
   cout << ' ';
   printDouble(point.y);
   cout << ' ';
   printDouble(point.z);
   cout << '\n';
}

// Pre:
// Post: overwrites the position of particle to updated one when it elapsed t (u.t);
void updateParticlePosition(Particle& particle, double t) {
   particle.p = sum(particle.p, mul(t, particle.v));
}

// Pre:
// Post: point is overwrited to zero
void setPointToZero(Point& point) {
   point.x = 0;
   point.y = 0;
   point.z = 0;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.setf(ios::fixed);
   cout.precision(5);

   int n, k;
   while (cin >> n >> k) {
      vector<Particle> particles(n);
      double TOTAL_MASS = 0;

      Point mass_center;
      setPointToZero(mass_center);

      Point mass_center_velocity;
      setPointToZero(mass_center_velocity);

      for (int i = 0; i < n; ++i) { // read particles values
         cin >> particles[i].p.x >> particles[i].p.y >> particles[i].p.z;
         cin >> particles[i].v.x >> particles[i].v.y >> particles[i].v.z;
         cin >> particles[i].m;
         mass_center = sum(mass_center, mul(particles[i].m, particles[i].p));
         mass_center_velocity = sum(mass_center_velocity, mul(particles[i].m, particles[i].v));
         TOTAL_MASS += particles[i].m;
      }

      double t; // time elapsed
      double t_total = 0;
      for (int i = 0; i < k; ++i) {
         cin >> t;
         mass_center = sum(mass_center, mul(t, mass_center_velocity));
         printPoint(div(TOTAL_MASS, mass_center));
         t_total += t;
      }

      for (int i = 0; i < n; ++i) {
         updateParticlePosition(particles[i], t_total);
         printPoint(particles[i].p);
      }

      cout << '\n';
   }
}