module SFML
  class Event
    # Common module for sub event objects
    module EventStruct
    end

    class SizeEvent
      include EventStruct
    end

    class TextEvent
      include EventStruct
    end

    class KeyEvent
      include EventStruct
    end

    class MouseWheelEvent
      include EventStruct
    end

    class MouseButtonEvent
      include EventStruct
    end

    class MouseMoveEvent
      include EventStruct
    end

    class JoystickButtonEvent
      include EventStruct
    end

    class JoystickMoveEvent
      include EventStruct
    end

    class JoystickConnectEvent
      include EventStruct
    end

    class TouchEvent
      include EventStruct
    end

    class SensorEvent
      include EventStruct
    end

    # @return [Object] event object
    def event
      case type
      when EventType::Closed,
           EventType::LostFocus,
           EventType::GainedFocus,
           EventType::MouseEntered,
           EventType::MouseLeft
        self
      when EventType::Resized
        size
      when EventType::TextEntered
        text
      when EventType::KeyPressed,
           EventType::KeyReleased
        key
      when EventType::MouseWheelMoved
        mouse_wheel
      when EventType::MouseButtonPressed,
           EventType::MouseButtonReleased
        mouse_button
      when EventType::MouseMoved
        mouse_move
      when EventType::JoystickButtonPressed,
           EventType::JoystickButtonReleased
        joystick_button
      when EventType::JoystickMoved
        joystick_move
      when EventType::JoystickConnected,
           EventType::JoystickDisconnected
        joystick_connect
      when EventType::TouchBegan,
           EventType::TouchMoved,
           EventType::TouchEnded,
        touch
      when EventType::SensorChanged
        sensor
      else
        raise
      end
    end
  end
end
