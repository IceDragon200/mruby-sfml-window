module SFML
  module Mouse
    class << self
      alias :button_pressed? :is_button_pressed
      alias :position :get_position
      alias :position= :set_position
    end
  end
end
