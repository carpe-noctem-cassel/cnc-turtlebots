classdef LogicalCamera3D < robotics.ros.Message
    %LogicalCamera3D MATLAB implementation of ttb_msgs/LogicalCamera3D
    %   This class was automatically generated by
    %   robotics.ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2014-2017 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'ttb_msgs/LogicalCamera3D' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = '751073689d1e227cb31ca296dcd22390' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Constant, Access = protected)
        GeometryMsgsPoseClass = robotics.ros.msg.internal.MessageFactory.getClassForType('geometry_msgs/Pose') % Dispatch to MATLAB class for message type geometry_msgs/Pose
        TimeClass = robotics.ros.msg.internal.MessageFactory.getClassForType('time') % Dispatch to MATLAB class for message type time
        TtbMsgsObjectSizeClass = robotics.ros.msg.internal.MessageFactory.getClassForType('ttb_msgs/ObjectSize') % Dispatch to MATLAB class for message type ttb_msgs/ObjectSize
    end
    
    properties (Dependent)
        ModelName
        Pose
        Size
        TimeStamp
        Type
    end
    
    properties (Access = protected)
        Cache = struct('Pose', [], 'Size', [], 'TimeStamp', []) % The cache for fast data access
    end
    
    properties (Constant, Hidden)
        PropertyList = {'ModelName', 'Pose', 'Size', 'TimeStamp', 'Type'} % List of non-constant message properties
        ROSPropertyList = {'modelName', 'pose', 'size', 'timeStamp', 'type'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = LogicalCamera3D(msg)
            %LogicalCamera3D Construct the message object LogicalCamera3D
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
        
        function modelname = get.ModelName(obj)
            %get.ModelName Get the value for property ModelName
            modelname = char(obj.JavaMessage.getModelName);
        end
        
        function set.ModelName(obj, modelname)
            %set.ModelName Set the value for property ModelName
            validateattributes(modelname, {'char'}, {}, 'LogicalCamera3D', 'ModelName');
            
            obj.JavaMessage.setModelName(modelname);
        end
        
        function pose = get.Pose(obj)
            %get.Pose Get the value for property Pose
            if isempty(obj.Cache.Pose)
                obj.Cache.Pose = feval(obj.GeometryMsgsPoseClass, obj.JavaMessage.getPose);
            end
            pose = obj.Cache.Pose;
        end
        
        function set.Pose(obj, pose)
            %set.Pose Set the value for property Pose
            validateattributes(pose, {obj.GeometryMsgsPoseClass}, {'nonempty', 'scalar'}, 'LogicalCamera3D', 'Pose');
            
            obj.JavaMessage.setPose(pose.getJavaObject);
            
            % Update cache if necessary
            if ~isempty(obj.Cache.Pose)
                obj.Cache.Pose.setJavaObject(pose.getJavaObject);
            end
        end
        
        function size = get.Size(obj)
            %get.Size Get the value for property Size
            if isempty(obj.Cache.Size)
                obj.Cache.Size = feval(obj.TtbMsgsObjectSizeClass, obj.JavaMessage.getSize);
            end
            size = obj.Cache.Size;
        end
        
        function set.Size(obj, size)
            %set.Size Set the value for property Size
            validateattributes(size, {obj.TtbMsgsObjectSizeClass}, {'nonempty', 'scalar'}, 'LogicalCamera3D', 'Size');
            
            obj.JavaMessage.setSize(size.getJavaObject);
            
            % Update cache if necessary
            if ~isempty(obj.Cache.Size)
                obj.Cache.Size.setJavaObject(size.getJavaObject);
            end
        end
        
        function timestamp = get.TimeStamp(obj)
            %get.TimeStamp Get the value for property TimeStamp
            if isempty(obj.Cache.TimeStamp)
                obj.Cache.TimeStamp = feval(obj.TimeClass, obj.JavaMessage.getTimeStamp);
            end
            timestamp = obj.Cache.TimeStamp;
        end
        
        function set.TimeStamp(obj, timestamp)
            %set.TimeStamp Set the value for property TimeStamp
            validateattributes(timestamp, {obj.TimeClass}, {'nonempty', 'scalar'}, 'LogicalCamera3D', 'TimeStamp');
            
            obj.JavaMessage.setTimeStamp(timestamp.getJavaObject);
            
            % Update cache if necessary
            if ~isempty(obj.Cache.TimeStamp)
                obj.Cache.TimeStamp.setJavaObject(timestamp.getJavaObject);
            end
        end
        
        function type = get.Type(obj)
            %get.Type Get the value for property Type
            type = char(obj.JavaMessage.getType);
        end
        
        function set.Type(obj, type)
            %set.Type Set the value for property Type
            validateattributes(type, {'char'}, {}, 'LogicalCamera3D', 'Type');
            
            obj.JavaMessage.setType(type);
        end
    end
    
    methods (Access = protected)
        function resetCache(obj)
            %resetCache Resets any cached properties
            obj.Cache.Pose = [];
            obj.Cache.Size = [];
            obj.Cache.TimeStamp = [];
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
            cpObj.ModelName = obj.ModelName;
            cpObj.Type = obj.Type;
            
            % Recursively copy compound properties
            cpObj.Pose = copy(obj.Pose);
            cpObj.Size = copy(obj.Size);
            cpObj.TimeStamp = copy(obj.TimeStamp);
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.ModelName = strObj.ModelName;
            obj.Type = strObj.Type;
            obj.Pose = feval([obj.GeometryMsgsPoseClass '.loadobj'], strObj.Pose);
            obj.Size = feval([obj.TtbMsgsObjectSizeClass '.loadobj'], strObj.Size);
            obj.TimeStamp = feval([obj.TimeClass '.loadobj'], strObj.TimeStamp);
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
            
            strObj.ModelName = obj.ModelName;
            strObj.Type = obj.Type;
            strObj.Pose = saveobj(obj.Pose);
            strObj.Size = saveobj(obj.Size);
            strObj.TimeStamp = saveobj(obj.TimeStamp);
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?robotics.ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = robotics.ros.custom.msggen.ttb_msgs.LogicalCamera3D.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = robotics.ros.custom.msggen.ttb_msgs.LogicalCamera3D;
            obj.reload(strObj);
        end
    end
end