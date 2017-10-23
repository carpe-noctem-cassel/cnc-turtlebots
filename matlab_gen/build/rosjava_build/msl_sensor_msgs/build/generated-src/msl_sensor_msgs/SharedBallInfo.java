package msl_sensor_msgs;

public interface SharedBallInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/SharedBallInfo";
  static final java.lang.String _DEFINITION = "msl_msgs/Point3dInfo point\nmsl_msgs/Velocity3dInfo velocity\nfloat64 confidence\nuint8 ballType\nint32 evidence\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  msl_msgs.Point3dInfo getPoint();
  void setPoint(msl_msgs.Point3dInfo value);
  msl_msgs.Velocity3dInfo getVelocity();
  void setVelocity(msl_msgs.Velocity3dInfo value);
  double getConfidence();
  void setConfidence(double value);
  byte getBallType();
  void setBallType(byte value);
  int getEvidence();
  void setEvidence(int value);
}
