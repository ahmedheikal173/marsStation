#include "formulationEvent.h"

formulationEvent::formulationEvent()
{
}



void formulationEvent::set_Type(char T)
{
	type = T;
}

int formulationEvent::get_Type()
{
	return type;
}

void formulationEvent::set_TargetLocation(int TLoc)
{
	targetLocation = TLoc;
}

int formulationEvent::get_TargetLocation()
{
	return targetLocation;
}

void formulationEvent::set_MissionDuration(int MDur)
{
	missionDuration = MDur;
}

int formulationEvent::get_MissionDuration()
{
	return missionDuration;
}

void formulationEvent::set_Significance(int Sig)
{
	significance = Sig;
}

int formulationEvent::get_Significance()
{
	return significance;
}

void formulationEvent::Execute(PriorityQueue<Mission>&EmergQ, LinkedQueue<Mission>&PolarQ)
{
	Mission* FM = new Mission() ;
	FM->setFD(get_EventDay());
	FM->setID(get_MissionID());
	FM->setType(type);
	FM->setMDUR(missionDuration);
	FM->settargetLoction(targetLocation);
	FM->setSignificance(significance);
	if (type == 'E')
		EmergQ.push(*FM,significance);//lazem neghayar esm push da -> ykoun enqueue IMPORTANT

	if (type == 'P')
		PolarQ.enqueue(*FM);

}