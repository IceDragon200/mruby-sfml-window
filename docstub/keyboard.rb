module SFML
  # Give access to the real-time state of the keyboard
  module Keyboard
    # Key codes
    module Key
      # @return [Integer]
      Unknown = -1
      # @return [Integer]
      A = 0
      # @return [Integer]
      B = 1
      # @return [Integer]
      C = 2
      # @return [Integer]
      D = 3
      # @return [Integer]
      E = 4
      # @return [Integer]
      F = 5
      # @return [Integer]
      G = 6
      # @return [Integer]
      H = 7
      # @return [Integer]
      I = 8
      # @return [Integer]
      J = 9
      # @return [Integer]
      K = 10
      # @return [Integer]
      L = 11
      # @return [Integer]
      M = 12
      # @return [Integer]
      N = 13
      # @return [Integer]
      O = 14
      # @return [Integer]
      P = 15
      # @return [Integer]
      Q = 16
      # @return [Integer]
      R = 17
      # @return [Integer]
      S = 18
      # @return [Integer]
      T = 19
      # @return [Integer]
      U = 20
      # @return [Integer]
      V = 21
      # @return [Integer]
      W = 22
      # @return [Integer]
      X = 23
      # @return [Integer]
      Y = 24
      # @return [Integer]
      Z = 25
      # @return [Integer]
      Num0 = 26
      # @return [Integer]
      Num1 = 27
      # @return [Integer]
      Num2 = 28
      # @return [Integer]
      Num3 = 29
      # @return [Integer]
      Num4 = 30
      # @return [Integer]
      Num5 = 31
      # @return [Integer]
      Num6 = 32
      # @return [Integer]
      Num7 = 33
      # @return [Integer]
      Num8 = 34
      # @return [Integer]
      Num9 = 35
      # @return [Integer]
      Escape = 36
      # @return [Integer]
      LControl = 37
      # @return [Integer]
      LShift = 38
      # @return [Integer]
      LAlt = 39
      # @return [Integer]
      LSystem = 40
      # @return [Integer]
      RControl = 41
      # @return [Integer]
      RShift = 42
      # @return [Integer]
      RAlt = 43
      # @return [Integer]
      RSystem = 44
      # @return [Integer]
      Menu = 45
      # @return [Integer]
      LBracket = 46
      # @return [Integer]
      RBracket = 47
      # @return [Integer]
      SemiColon = 48
      # @return [Integer]
      Comma = 49
      # @return [Integer]
      Period = 50
      # @return [Integer]
      Quote = 51
      # @return [Integer]
      Slash = 52
      # @return [Integer]
      BackSlash = 53
      # @return [Integer]
      Tilde = 54
      # @return [Integer]
      Equal = 55
      # @return [Integer]
      Dash = 56
      # @return [Integer]
      Space = 57
      # @return [Integer]
      Return = 58
      # @return [Integer]
      BackSpace = 59
      # @return [Integer]
      Tab = 60
      # @return [Integer]
      PageUp = 61
      # @return [Integer]
      PageDown = 62
      # @return [Integer]
      End = 63
      # @return [Integer]
      Home = 64
      # @return [Integer]
      Insert = 65
      # @return [Integer]
      Delete = 66
      # @return [Integer]
      Add = 67
      # @return [Integer]
      Subtract = 68
      # @return [Integer]
      Multiply = 69
      # @return [Integer]
      Divide = 70
      # @return [Integer]
      Left = 71
      # @return [Integer]
      Right = 72
      # @return [Integer]
      Up = 73
      # @return [Integer]
      Down = 74
      # @return [Integer]
      Numpad0 = 75
      # @return [Integer]
      Numpad1 = 76
      # @return [Integer]
      Numpad2 = 77
      # @return [Integer]
      Numpad3 = 78
      # @return [Integer]
      Numpad4 = 79
      # @return [Integer]
      Numpad5 = 80
      # @return [Integer]
      Numpad6 = 81
      # @return [Integer]
      Numpad7 = 82
      # @return [Integer]
      Numpad8 = 83
      # @return [Integer]
      Numpad9 = 84
      # @return [Integer]
      F1 = 85
      # @return [Integer]
      F2 = 86
      # @return [Integer]
      F3 = 87
      # @return [Integer]
      F4 = 88
      # @return [Integer]
      F5 = 89
      # @return [Integer]
      F6 = 90
      # @return [Integer]
      F7 = 91
      # @return [Integer]
      F8 = 92
      # @return [Integer]
      F9 = 93
      # @return [Integer]
      F10 = 94
      # @return [Integer]
      F11 = 95
      # @return [Integer]
      F12 = 96
      # @return [Integer]
      F13 = 97
      # @return [Integer]
      F14 = 98
      # @return [Integer]
      F15 = 99
      # @return [Integer]
      Pause = 100
      # @return [Integer] total number of available keys
      KeyCount = 101
    end

    # Check if a key is pressed
    #
    # @param [Key] key  Key to check
    # @return [Boolean] true if the key is pressed, false otherwise
    def is_key_pressed(key)
    end

    # Show or hide the virtual keyboard
    #
    # Warning: the virtual keyboard is not supported on all
    # systems. It will typically be implemented on mobile OSes
    # (Android, iOS) but not on desktop OSes (Windows, Linux, ...).
    #
    # If the virtual keyboard is not available, this function does
    # nothing.
    #
    # @param [Boolean] visible  true to show, false to hide
    # @return [self]
    def set_virtual_keyboard_visible(visible)
    end
  end
end
