/* We use skeltrack to extract skeleton information and it is used to predict gesture of user. Predicted gesture is returned at output screen.
 */
#include "SkeltrackHeuristicGestures.h"


/*! \fn void SkeltrackHeuristicGestures::createObjects()
 *  \brief Creates GObjects corresponding to Kinect and Skeltrack.
 */
void SkeltrackHeuristicGestures::createObjects(Gobject *obj, GAsyncResult *res, gpointer user_data)
{
	GError *error = NULL;
	gint width = 640;
	gint height = 480;
	kinect = gfreenect_device_new_finish(res, &error);
	if (kinect == NULL)
	{
		g_debug("Failed to create Kinect device: %s", error->message);
		g_error_free(error);
		return;
	}
	g_debug("Kinect device created!!");
	skeleton = skeltrack_skeleton_new();	
	// TODO: Code for setting smoothing factor and threshold using OpenCV GUI
	g_signal_connect(kinect, "depth-frame", G_CALLBACK(recieveDepthFrame));
	g_signal_connect(kinect, "video-frame", G_CALLBACK(recieveVideoFrame));
	// TODO: add code to draw skeleton in a window in GUI
	gfreenect_device_set_tilt_angle(kinect, 0, NULL, NULL, NULL);
	gfreenect_device_start_depth_stream(kinect, GFREENECT_DEPTH_FORMAT_MM, NULL);
	gfreenect_device_start_video_stream(kinect, GFREENECT_RESOLUTION_MEDIUM, GFREENECT_VIDEO_FORMAT_RGB, NULL);
	// TODO: add code for showing the video and depth stream from Kinect in GUI window.

}


/*! \fn static void SkeltrackHeuristicGestures::quit(gint signale)
 *  \brief Terminates execution.
 */
static void SkeltrackHeuristicGestures::quit(gint signale)
{
	signal(SIGINT, 0);
}


/*! \fn void SkeltrackHeuristicGestures::initializeSkeltrack()
 *  \brief Initializes kinect object and then associates corresponding Skeltrack object.
 */
void SkeltrackHeuristicGestures::initialize()
{
	gfreenect_device_new(0, GFREENECT_SUBDEVICE_CAMERA, NULL, createObjects, NULL);
	signal(SIGINT, quit);
	
}


/*! \fn void SkeltrackGesture::extractSkeletonJoints()
 *  \brief Receives coordinates of skeleton from Skeltrack library interface */
void SkeltrackHeuristicGestures::extractSkeletonJoints()
{
		
}


/*! \fn void SkeltrackHeuristicGestures::predictSkeletonGesture()
 *  \brief Predicts the gesture given joint coordinates.
 */
void SkeltrackHeuristicGestures::predictSkeletonGesture()
{

}


/*! \fn void SkeltrackHeuristicGestures::showGesture()
 *  \brief Shows predicted gesture.
 */
void SkeltrackHeuristicGestures::showGesture()
{
}	


/*! \fn void SkeltrackHeuristicGestures::destroyObjects()
 *  \brief De-allocates all gobjects.
 */
void SkeltrackHeuristicGestures::destroyObjects()
{
	if (kinect != NULL)
		g_object_unref(kinect);
	if (skeleton != NULL)
		g_object_unref(skeleton);
}

