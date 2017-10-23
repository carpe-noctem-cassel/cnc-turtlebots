classdef BallInfo < robotics.ros.Message
    %BallInfo MATLAB implementation of msl_sensor_msgs/BallInfo
    %   This class was automatically generated by
    %   robotics.ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2014-2017 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'msl_sensor_msgs/BallInfo' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = 'faad244990139856d77aa59d29bbea84' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Constant, Access = protected)
        MslMsgsPoint3dInfoClass = robotics.ros.msg.internal.MessageFactory.getClassForType('msl_msgs/Point3dInfo') % Dispatch to MATLAB class for message type msl_msgs/Point3dInfo
        MslMsgsVelocity3dInfoClass = robotics.ros.msg.internal.MessageFactory.getClassForType('msl_msgs/Velocity3dInfo') % Dispatch to MATLAB class for message type msl_msgs/Velocity3dInfo
    end
    
    properties (Dependent)
        Point
        Velocity
        Confidence
        BallType
    end
    
    properties (Access = protected)
        Cache = struct('Point', [], 'Velocity', []) % The cache for fast data access
    end
    
    properties (Constant, Hidden)
        PropertyList = {'BallType', 'Confidence', 'Point', 'Velocity'} % List of non-constant message properties
        ROSPropertyList = {'ballType', 'confidence', 'point', 'velocity'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = BallInfo(msg)
            %BallInfo Construct the message object BallInfo
            import com.mathworks.toolbox.robotics.ros.message.MessageInfo;
            
            % Support default constructor
            if nargin == 0
                obj.JavaMessage = obj.createNewJavaMessage;
                return;
            end
            
            % Construct appropriate empty array
            if isempty(msg)
                obj = obj.empty(0,1);
                return;
            end
            
            % Make scalar construction fast
            if isscalar(msg)
                % Check for correct input class
                if ~MessageInfo.compareTypes(msg(1), obj.MessageType)
                    error(message('robotics:ros:message:NoTypeMatch', obj.MessageType, ...
                        char(MessageInfo.getType(msg(1))) ));
                end
                obj.JavaMessage = msg(1);
                return;
            end
            
            % Check that this is a vector of scalar messages. Since this
            % is an object array, use arrayfun to verify.
            if ~all(arrayfun(@isscalar, msg))
                error(message('robotics:ros:message:MessageArraySizeError'));
            end
            
            % Check that all messages in the array have the correct type
            if ~all(arrayfun(@(x) MessageInfo.compareTypes(x, obj.MessageType), msg))
                error(message('robotics:ros:message:NoTypeMatchArray', obj.MessageType));
            end
            
            % Construct array of objects if necessary
            objType = class(obj);
            for i = 1:length(msg)
                obj(i,1) = feval(objType, msg(i)); %#ok<AGROW>
            end
        end
        
        function point = get.Point(obj)
            %get.Point Get the value for property Point
            if isempty(obj.Cache.Point)
                obj.Cache.Point = feval(obj.MslMsgsPoint3dInfoClass, obj.JavaMessage.getPoint);
            end
            point = obj.Cache.Point;
        end
        
        function set.Point(obj, point)
            %set.Point Set the value for property Point
            validateattributes(point, {obj.MslMsgsPoint3dInfoClass}, {'nonempty', 'scalar'}, 'BallInfo', 'Point');
            
            obj.JavaMessage.setPoint(point.getJavaObject);
            
            % Update cache if necessary
            if ~isempty(obj.Cache.Point)
                obj.Cache.Point.setJavaObject(point.getJavaObject);
            end
        end
        
        function velocity = get.Velocity(obj)
            %get.Velocity Get the value for property Velocity
            if isempty(obj.Cache.Velocity)
                obj.Cache.Velocity = feval(obj.MslMsgsVelocity3dInfoClass, obj.JavaMessage.getVelocity);
            end
            velocity = obj.Cache.Velocity;
        end
        
        function set.Velocity(obj, velocity)
            %set.Velocity Set the value for property Velocity
            validateattributes(velocity, {obj.MslMsgsVelocity3dInfoClass}, {'nonempty', 'scalar'}, 'BallInfo', 'Velocity');
            
            obj.JavaMessage.setVelocity(velocity.getJavaObject);
            
            % Update cache if necessary
            if ~isempty(obj.Cache.Velocity)
                obj.Cache.Velocity.setJavaObject(velocity.getJavaObject);
            end
        end
        
        function confidence = get.Confidence(obj)
            %get.Confidence Get the value for property Confidence
            confidence = double(obj.JavaMessage.getConfidence);
        end
        
        function set.Confidence(obj, confidence)
            %set.Confidence Set the value for property Confidence
            validateattributes(confidence, {'numeric'}, {'nonempty', 'scalar'}, 'BallInfo', 'Confidence');
            
            obj.JavaMessage.setConfidence(confidence);
        end
        
        function balltype = get.BallType(obj)
            %get.BallType Get the value for property BallType
            balltype = typecast(int8(obj.JavaMessage.getBallType), 'uint8');
        end
        
        function set.BallType(obj, balltype)
            %set.BallType Set the value for property BallType
            validateattributes(balltype, {'numeric'}, {'nonempty', 'scalar'}, 'BallInfo', 'BallType');
            
            obj.JavaMessage.setBallType(balltype);
        end
    end
    
    methods (Access = protected)
        function resetCache(obj)
            %resetCache Resets any cached properties
            obj.Cache.Point = [];
            obj.Cache.Velocity = [];
        end
        
        function cpObj = copyElement(obj)
            %copyElement Implements deep copy behavior for message
            
            % Call default copy method for shallow copy
            cpObj = copyElement@robotics.ros.Message(obj);
            
            % Clear any existing cached properties
            cpObj.resetCache;
            
            % Create a new Java message object
            cpObj.JavaMessage = obj.createNewJavaMessage;
            
            % Iterate over all primitive properties
            cpObj.Confidence = obj.Confidence;
            cpObj.BallType = obj.BallType;
            
            % Recursively copy compound properties
            cpObj.Point = copy(obj.Point);
            cpObj.Velocity = copy(obj.Velocity);
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.Confidence = strObj.Confidence;
            obj.BallType = strObj.BallType;
            obj.Point = feval([obj.MslMsgsPoint3dInfoClass '.loadobj'], strObj.Point);
            obj.Velocity = feval([obj.MslMsgsVelocity3dInfoClass '.loadobj'], strObj.Velocity);
        end
    end
    
    methods (Access = ?robotics.ros.Message)
        function strObj = saveobj(obj)
            %saveobj Implements saving of message to MAT file
            
            % Return an empty element if object array is empty
            if isempty(obj)
                strObj = struct.empty;
                return
            end
            
            strObj.Confidence = obj.Confidence;
            strObj.BallType = obj.BallType;
            strObj.Point = saveobj(obj.Point);
            strObj.Velocity = saveobj(obj.Velocity);
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?robotics.ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = robotics.ros.custom.msggen.msl_sensor_msgs.BallInfo.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = robotics.ros.custom.msggen.msl_sensor_msgs.BallInfo;
            obj.reload(strObj);
        end
    end
end
