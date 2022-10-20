#pragma once

#include "ImaginaryEngine/Core.h"

#include <string>
#include <functional>

namespace ImaginaryEngine
{
	enum class EventType
	{
		None=0,
		WindowClode,WindowResize,WindowFocus,WindowLostFocus,WindowMoved,
		AppTick,AppUpdate,AppRender,
		KeyPressed,KeyReleased,
		MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4),
	};

	#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType(){ retuen EventType::##type;}\
									virtual EventType GetEventType()const override { return GetStaticType();}\
									virtual const char* GetName() const override {return #type;}

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const ovverride { return category; }

	class IMAGINARY_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() = 0;
		virtual int GetCategoryFlags() = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
		
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() && category;
		}
	
	protected:
		bool _Handled = false;
	};
	
	class EventDispatcher
	{
	public:
		

	private:

	};

	

	#define BIT(x) (1<<x)
}