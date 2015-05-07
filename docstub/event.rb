module SFML
  # Defines a system event and its parameters
  class Event
    # Enumeration of the different types of events
    module EventType
      # @return [Integer]
      Closed = 0
      # @return [Integer]
      Resized = 1
      # @return [Integer]
      LostFocus = 2
      # @return [Integer]
      GainedFocus = 3
      # @return [Integer]
      TextEntered = 4
      # @return [Integer]
      KeyPressed = 5
      # @return [Integer]
      KeyReleased = 6
      # @return [Integer]
      MouseWheelMoved = 7
      # @return [Integer]
      MouseButtonPressed = 8
      # @return [Integer]
      MouseButtonReleased = 9
      # @return [Integer]
      MouseMoved = 10
      # @return [Integer]
      MouseEntered = 11
      # @return [Integer]
      MouseLeft = 12
      # @return [Integer]
      JoystickButtonPressed = 13
      # @return [Integer]
      JoystickButtonReleased = 14
      # @return [Integer]
      JoystickMoved = 15
      # @return [Integer]
      JoystickConnected = 16
      # @return [Integer]
      JoystickDisconnected = 17
      # @return [Integer]
      TouchBegan = 18
      # @return [Integer]
      TouchMoved = 19
      # @return [Integer]
      TouchEnded = 20
      # @return [Integer]
      SensorChanged = 21
      # @return [Integer]
      Count = 22
    end

    def initialize
    end

    # @return [EventType]
    def type
    end

    # @return [SizeEvent]
    def size
    end

    # @return [KeyEvent]
    def key
    end

    # @return [TextEvent]
    def text
    end

    # @return [MouseMoveEvent]
    def mouse_move
    end

    # @return [MouseButtonEvent]
    def mouse_button
    end

    # @return [MouseWheelEvent]
    def mouse_wheel
    end

    # @return [JoystickMoveEvent]
    def joystick_move
    end

    # @return [JoystickButtonEvent]
    def joystick_button
    end

    # @return [JoystickConnectEvent]
    def joystick_connect
    end

    # @return [JoystickTouchEvent]
    def touch
    end

    # @return [SensorEvent]
    def sensor
    end
  end
end
