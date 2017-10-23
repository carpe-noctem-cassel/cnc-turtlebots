classdef ServeTask < robotics.ros.Message
    %ServeTask MATLAB implementation of ttb_msgs/ServeTask
    %   This class was automatically generated by
    %   robotics.ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2014-2017 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'ttb_msgs/ServeTask' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = '212ab28a76530201dd094edd1ba01064' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Constant)
        PICKUP = uint8(0)
        PUTDOWN = uint8(1)
        SEARCH = uint8(2)
        DRIVETO = uint8(3)
    end
    
    properties (Dependent)
        SenderId
        ReceiverId
        Type
        Entity
    end
    
    properties (Constant, Hidden)
        PropertyList = {'Entity', 'ReceiverId', 'SenderId', 'Type'} % List of non-constant message properties
        ROSPropertyList = {'entity', 'receiverId', 'senderId', 'type'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = ServeTask(msg)
            %ServeTask Construct the message object ServeTask
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
        
        function senderid = get.SenderId(obj)
            %get.SenderId Get the value for property SenderId
            senderid = int32(obj.JavaMessage.getSenderId);
        end
        
        function set.SenderId(obj, senderid)
            %set.SenderId Set the value for property SenderId
            validateattributes(senderid, {'numeric'}, {'nonempty', 'scalar'}, 'ServeTask', 'SenderId');
            
            obj.JavaMessage.setSenderId(senderid);
        end
        
        function receiverid = get.ReceiverId(obj)
            %get.ReceiverId Get the value for property ReceiverId
            receiverid = int32(obj.JavaMessage.getReceiverId);
        end
        
        function set.ReceiverId(obj, receiverid)
            %set.ReceiverId Set the value for property ReceiverId
            validateattributes(receiverid, {'numeric'}, {'nonempty', 'scalar'}, 'ServeTask', 'ReceiverId');
            
            obj.JavaMessage.setReceiverId(receiverid);
        end
        
        function type = get.Type(obj)
            %get.Type Get the value for property Type
            type = typecast(int8(obj.JavaMessage.getType), 'uint8');
        end
        
        function set.Type(obj, type)
            %set.Type Set the value for property Type
            validateattributes(type, {'numeric'}, {'nonempty', 'scalar'}, 'ServeTask', 'Type');
            
            obj.JavaMessage.setType(type);
        end
        
        function entity = get.Entity(obj)
            %get.Entity Get the value for property Entity
            entity = char(obj.JavaMessage.getEntity);
        end
        
        function set.Entity(obj, entity)
            %set.Entity Set the value for property Entity
            validateattributes(entity, {'char'}, {}, 'ServeTask', 'Entity');
            
            obj.JavaMessage.setEntity(entity);
        end
    end
    
    methods (Access = protected)
        function cpObj = copyElement(obj)
            %copyElement Implements deep copy behavior for message
            
            % Call default copy method for shallow copy
            cpObj = copyElement@robotics.ros.Message(obj);
            
            % Create a new Java message object
            cpObj.JavaMessage = obj.createNewJavaMessage;
            
            % Iterate over all primitive properties
            cpObj.SenderId = obj.SenderId;
            cpObj.ReceiverId = obj.ReceiverId;
            cpObj.Type = obj.Type;
            cpObj.Entity = obj.Entity;
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.SenderId = strObj.SenderId;
            obj.ReceiverId = strObj.ReceiverId;
            obj.Type = strObj.Type;
            obj.Entity = strObj.Entity;
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
            
            strObj.SenderId = obj.SenderId;
            strObj.ReceiverId = obj.ReceiverId;
            strObj.Type = obj.Type;
            strObj.Entity = obj.Entity;
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?robotics.ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = robotics.ros.custom.msggen.ttb_msgs.ServeTask.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = robotics.ros.custom.msggen.ttb_msgs.ServeTask;
            obj.reload(strObj);
        end
    end
end