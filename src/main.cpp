/* Top level source file for this project.
*/
#include "SkeltrackHeuristicGestures.h"

int main()
{
	SkeltrackGesture sg;
	char userResponse = NULL;

	while(userResponse != 'e')
	{
		sg.extractSkeletonJoints();
		sg.predictSkeletonGesture(); // sets predicted gesture in a protected data member
		sg.showGesture(); // displays Name of gesture for predicted gesture
		// TODO: Is there any system function equivalent to cvWaitKey() ?
		userResponse = cvWaitKey(); 
	}

	return 0;
}
