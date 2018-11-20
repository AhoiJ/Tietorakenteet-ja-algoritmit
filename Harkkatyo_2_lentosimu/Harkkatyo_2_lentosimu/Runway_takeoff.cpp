#include "Runway_takeoff.h"
#include "Extended_queue.h"
#include "Queue.h"


Runway_takeoff::Runway_takeoff(int limit)
/*
Post:  The Runway data members are initialized to record no
prior Runway use and to record the limit on queue sizes.
*/

{
	queue_limit = limit;
	num_land_requests = num_takeoff_requests = 0;
	num_landings = num_takeoffs = 0;
	num_land_refused = num_takeoff_refused = 0;
	num_land_accepted = num_takeoff_accepted = 0;
	land_wait = takeoff_wait = idle_time = 0;
}


Error_code Runway_takeoff::can_land(const Plane &current)
/*
Post:  If possible, the Plane current is added to the
landing Queue; otherwise, an Error_code of overflow is
returned. The Runway statistics are updated.
Uses:  class Extended_queue.
*/

{
	Error_code result;
	if (landing.size() < queue_limit)
		result = landing.append(current);
	else
		result = fail;
	num_land_requests++;

	if (result != success)
		num_land_refused++;
	else
		num_land_accepted++;

	return result;
}


Error_code Runway_takeoff::can_depart(const Plane &current)
/*
Post:  If possible, the Plane current is added to the
takeoff Queue; otherwise, an Error_code of overflow is
returned. The Runway statistics are updated.
Uses:  class Extended_queue.
*/

{
	Error_code result;
	if (takeoff.size() < queue_limit)
		result = takeoff.append(current);
	else
		result = fail;
	num_takeoff_requests++;
	if (result != success)
		num_takeoff_refused++;
	else
		num_takeoff_accepted++;

	return result;
}

Runway_activity Runway_takeoff::activity(int time, Plane &moving)
/*
Post:  If the landing Queue has entries, its front
Plane is copied to the parameter moving
and a result  land is returned. Otherwise,
if the takeoff Queue has entries, its front
Plane is copied to the parameter moving
and a result  takeoff is returned. Otherwise,
idle is returned. Runway statistics are updated.
Uses:  class Extended_queue.
*/

{
	Runway_activity in_progress;
	if (!landing.empty()) {
		landing.retrieve(moving);
		land_wait += time - moving.started();
		num_landings++;
		in_progress = land;
		landing.serve();
	}

	else if (!takeoff.empty()) {
		takeoff.retrieve(moving);
		takeoff_wait += time - moving.started();
		num_takeoffs++;
		in_progress = takingoff;
		takeoff.serve();
	}

	else {
		idle_time++;
		in_progress = idle;
	}
	return in_progress;
}

void Runway_takeoff::shut_down(int time) const
/*
Post: Runway usage statistics are summarized and printed.
*/

{
	cout << "Simulation has concluded after " << time << " time units." << endl
		<< "Takeoff Runway : " << endl
		<< "Total number of planes processed "
		<< (num_land_requests + num_takeoff_requests) << endl
		<< "Total number of planes asking to take off "
		<< num_takeoff_requests << endl
		<< "Total number of planes accepted for takeoff "
		<< num_takeoff_accepted << endl
		<< "Total number of planes refused for takeoff "
		<< num_takeoff_refused << endl
		<< "Total number of planes that took off "
		<< num_takeoffs << endl
		<< "Total number of planes left in takeoff queue "
		<< takeoff.size() << endl;
	cout << "Percentage of time runway idle "
		<< 100.0 * ((float)idle_time) / ((float)time) << "%" << endl;
	cout << endl << "Average wait in takeoff queue "
		<< ((float)takeoff_wait) / ((float)num_takeoffs)
		<< " time units" << endl;
	cout << "Average observed rate of planes wanting to take off "
		<< ((float)num_takeoff_requests) / ((float)time)
		<< " per time unit" << endl;
}