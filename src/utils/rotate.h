#ifndef __ROTATE_H
#define __ROTATE_H

#include <QObject>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <linux/input.h>

#include <QTimer>


/**
 * Detects the orientation of the device, and will rotate the screen
 * in the direction indicated by the orientation
 */

class RotateHelper : public QObject
{
    Q_OBJECT

 public:
	RotateHelper(QObject *parent= 0, int debug= 0);
	~RotateHelper();
	void start(int timerms= 500);
	void stop();
	void restore();
	bool isLandscape();
	void accel_sample(double acx, double acy, double acz);

 private slots:
	void sample();

signals:
     void rotated(bool landscape);

 private:
	void maybe_rotate(int deg);
	int neighbour(int value, int target, int neighbour);
	int define_position(void);
	bool packet_reader();

	enum Orientation {UP=0, RIGHT=90, DOWN=180, LEFT=270};

	int x;
	int y;
	int z;
	
	/* Position flags */
	int face_up;
	int vertical;
	int left;
	int right;
	int up;
	int down;
	int last_pos;
	int current_pos;
	int debug;
	int initial_rotation;

	static void accel_callback(void *closure,
				   double acx,
				   double acy,
				   double acz);
};
#endif
