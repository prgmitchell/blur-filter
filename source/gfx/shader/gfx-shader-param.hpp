// AUTOGENERATED COPYRIGHT HEADER START
// Copyright (C) 2019-2023 Michael Fabian 'Xaymar' Dirks <info@xaymar.com>
// Copyright (C) 2021 coolsoft.rf <coolsoft.rf@gmail.com>
// Copyright (C) 2022 lainon <GermanAizek@yandex.ru>
// AUTOGENERATED COPYRIGHT HEADER END

#pragma once
#include "obs/gs/gs-effect-parameter.hpp"

#include "warning-disable.hpp"
#include <list>
#include <string>
#include "warning-enable.hpp"

namespace streamfx::gfx {
	namespace shader {
		class shader;

		enum class parameter_type {
			// Unknown type, could be anything.
			Unknown,
			// Boolean, either false or true.
			Boolean,
			// Single Floating Point
			Float,
			// 32-Bit Integer
			Integer,
			// UTF-8 Character based String.
			String,
			// Texture with dimensions stored in size (1 = Texture1D, 2 = Texture2D, 3 = Texture3D, 6 = TextureCube).
			Texture,
			// Sampler for Textures.
			Sampler
		};

		parameter_type get_type_from_effect_type(streamfx::obs::gs::effect_parameter::type type);

		std::size_t get_length_from_effect_type(streamfx::obs::gs::effect_parameter::type type);

		parameter_type get_type_from_string(std::string_view v);

		class parameter {
			// Parent Shader
			streamfx::gfx::shader::shader* _parent;

			// Parameter used for all functionality.
			streamfx::obs::gs::effect_parameter _param;

			// Real type of the parameter (libobs gets it wrong often).
			parameter_type _type;

			// Real size of the parameter (libobs gets it wrong often).
			std::size_t _size;

			// Order of the parameter in a list/map.
			int32_t _order;

			// Key for the parameter (group) in a list/map.
			std::string _key;

			// Visibility, name and description.
			bool        _visible;
			bool        _automatic;
			std::string _name;
			std::string _description;

			protected:
			parameter(streamfx::gfx::shader::shader* parent, streamfx::obs::gs::effect_parameter param,
					  std::string key_prefix);
			virtual ~parameter(){};

			public:
			virtual void defaults(obs_data_t* settings);

			virtual void properties(obs_properties_t* props, obs_data_t* settings);

			virtual void update(obs_data_t* settings);

			virtual void assign();

			virtual void visible(bool visible);

			virtual void active(bool enabled);

			public:
			inline streamfx::gfx::shader::shader* get_parent()
			{
				return _parent;
			}

			inline streamfx::obs::gs::effect_parameter get_parameter()
			{
				return _param;
			}

			inline parameter_type get_type()
			{
				return _type;
			}

			inline std::size_t get_size()
			{
				return _size;
			}

			inline int32_t get_order()
			{
				return _order;
			}

			inline std::string_view get_key()
			{
				return _key;
			}

			inline bool is_visible()
			{
				return _visible && !_automatic;
			}

			inline bool is_automatic()
			{
				return _automatic;
			}

			inline bool has_name()
			{
				return _name.length() > 0;
			}

			inline std::string_view get_name()
			{
				return _name;
			}

			inline bool has_description()
			{
				return _description.length() > 0;
			}

			inline std::string_view get_description()
			{
				return _description;
			}

			public:
			static std::shared_ptr<parameter> make_parameter(streamfx::gfx::shader::shader*      parent,
															 streamfx::obs::gs::effect_parameter param,
															 std::string                         prefix);
		};
	} // namespace shader
} // namespace streamfx::gfx