MRuby::Gem::Specification.new('mruby-sfml-window') do |spec|
  spec.license = 'MIT'
  spec.authors = ['Corey Powell']
  spec.version = '2.2.0.0'
  spec.summary = 'SFML Window binding'
  spec.description = 'SFML Window binding'
  spec.homepage = 'https://github.com/IceDragon200/mruby-sfml-window'

  spec.add_dependency 'mruby-sfml-system', github: 'IceDragon200/mruby-sfml-system'
end
