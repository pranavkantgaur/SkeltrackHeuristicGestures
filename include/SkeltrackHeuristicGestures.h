#include <skeltrack-0.1/skeltrack.h>

/*! class SkeltrackGesture
 *  \brief Model of gesture recognizer based on Skeltrack.
 */
class SkeltrackHeuristicGestures
{
	public:
		void initializeSkeltrack();
		void extractSkeletonJoints();
		void predictSkeletonGesture();
		void showGesture();
	protected:
		size_t predictedGestureID;
};
