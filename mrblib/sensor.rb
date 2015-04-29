module SFML
  module Sensor
    class << self
      alias :available? :is_available
      alias :value :get_value
    end

    # Shortcut for: `set_enabled +sensor+, true`
    #
    # @param [Type] sensor
    def self.enable(sensor)
      set_enabled sensor, true
    end

    # Shortcut for: `set_enabled +sensor+, false`
    #
    # @param [Type] sensor
    def self.disable(sensor)
      set_enabled sensor, false
    end
  end
end
