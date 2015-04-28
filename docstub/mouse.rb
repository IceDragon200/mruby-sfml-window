module SFML
  module Mouse
    # Mouse buttons
    module Button
      # @return [Integer]
      Left = 0
      # @return [Integer]
      Right = 1
      # @return [Integer]
      Middle = 2
      # @return [Integer]
      XButton1 = 3
      # @return [Integer]
      XButton2 = 4
      # @return [Integer]
      ButtonCount = 5
    end

    # Mouse wheels
    module Wheel
      # @return [Integer]
      VerticalWheel = 0
      # @return [Integer]
      HorizontalWheel = 1
    end

    # @param [Button]
    # @return [Boolean]
    def self.is_button_pressed(button)
    end

    # @return [Vector2i]
    def self.get_position
    end

    # @param [Vector2i] position
    # @return [self]
    def self.set_position(position)
    end
  end
end
