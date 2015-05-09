module SFML
  # Defines a system event and its parameters
  class Event
    # Size events parameters (Resized)
    class SizeEvent
      attr_accessor :width
      attr_accessor :height
    end

    # Keyboard event parameters (KeyPressed, KeyReleased)
    class KeyEvent
      attr_reader :code
      attr_reader :alt
      attr_reader :control
      attr_reader :shift
      attr_reader :system
    end

    # Text event parameters (TextEntered)
    class TextEvent
      attr_reader :unicode
    end

    # Mouse move event parameters (MouseMoved)
    class MouseMoveEvent
      attr_reader :x
      attr_reader :y
    end

    # Mouse buttons events parameters
    # (MouseButtonPressed, MouseButtonReleased)
    class MouseButtonEvent
      attr_reader :button
      attr_reader :x
      attr_reader :y
    end

    # Mouse wheel events parameters (MouseWheelMoved)
    class MouseWheelEvent
      attr_reader :delta
      attr_reader :x
      attr_reader :y
    end

    # Joystick connection events parameters
    # (JoystickConnected, JoystickDisconnected)
    class JoystickConnectEvent
      attr_reader :joystick_id
    end

    # Joystick axis move event parameters (JoystickMoved)
    class JoystickMoveEvent
      attr_reader :joystick_id
      attr_reader :axis
      attr_reader :position
    end

    # Joystick buttons events parameters
    # (JoystickButtonPressed, JoystickButtonReleased)
    class JoystickButtonEvent
      attr_reader :joystick_id
      attr_reader :button
    end

    # Touch events parameters (TouchBegan, TouchMoved, TouchEnded)
    class TouchEvent
      attr_reader :finger
      attr_reader :x
      attr_reader :y
    end

    # Sensor event parameters (SensorChanged)
    class SensorEvent
      attr_reader :type
      attr_reader :x
      attr_reader :y
      attr_reader :z
    end

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

    # @return [EventType]
    attr_reader :type

    # @return [SizeEvent]
    attr_reader :size

    # @return [KeyEvent]
    attr_reader :key

    # @return [TextEvent]
    attr_reader :text

    # @return [MouseMoveEvent]
    attr_reader :mouse_move

    # @return [MouseButtonEvent]
    attr_reader :mouse_button

    # @return [MouseWheelEvent]
    attr_reader :mouse_wheel

    # @return [JoystickMoveEvent]
    attr_reader :joystick_move

    # @return [JoystickButtonEvent]
    attr_reader :joystick_button

    # @return [JoystickConnectEvent]
    attr_reader :joystick_connect

    # @return [JoystickTouchEvent]
    attr_reader :touch

    # @return [SensorEvent]
    attr_reader :sensor

    def initialize
    end
  end
end
