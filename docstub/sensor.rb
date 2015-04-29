module SFML
  # Give access to the real-time state of the sensors
  module Sensor
    # Sensor type
    module Type
      # @return [Integer]
      Accelerometer = 0
      # @return [Integer]
      Gyroscope = 1
      # @return [Integer]
      Magnetometer = 2
      # @return [Integer]
      Gravity = 3
      # @return [Integer]
      UserAcceleration = 4
      # @return [Integer]
      Orientation = 5
      # @return [Integer]
      Count = 6
    end

    # @param [Type] sensor
    # @return [Boolean]
    def is_available(sensor)
    end

    # @param [Type] sensor
    # @param [Boolean] enabled
    # @return [self]
    def set_enabled(sensor, enabled)
    end

    # @param [Type] sensor
    # @return [Vector3f]
    def get_value(sensor)
    end
  end
end
