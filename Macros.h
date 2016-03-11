//
//  Macros.h
//  macroProject
//
//  Created by Ray on 16/3/7.
//  Copyright © 2016年 Ray. All rights reserved.
//

#ifndef Macros_h
#define Macros_h


/**
 *  GCD macro
 */


/**
 *  Block
 */



/**
 *  UIView
 */
#define Center_Vertically(parent,child)         floor((parent.frame.size.height - child.frame.size.height) / 2)
#define Center_Horizontally(parent,child)       floor((parent.frame.size.width - child.frame.size.width) / 2)
#define Center_In_Parent_X(parent,childWidth)   floor((parent.frame.size.width - childWidth) / 2)
#define Center_In_Parent_Y(parent,childHeight)  floor((parent.frame.size.height - childHeight) / 2)

#define Width(view)     view.frame.size.width
#define Height(view)    view.frame.size.height
#define Left(view)      view.frame.origin.x
#define Top(view)       view.frame.origin.y
#define Bottom(view)    (view.frame.origin.y + view.frame.size.height)
#define Right(view)     (view.frame.origin.x + view.frame.size.width)


/**
 *  CALayer
 */


/**
 *  UIColor
 */
#define UIColorFromHex(hexValue)    UIColorFromHexWithAlpha(hexValue,1.0)
#define UIColorFromHexWithAlpha(hexValue,a) [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0 green:((float)((hexValue & 0xFF00) >> 8))/255.0 blue:((float)(hexValue & 0xFF))/255.0 alpha:a]
#define UIColorFromRGBA(r,g,b,a)    [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define UIColorFromRGB(r,g,b)       UIColorFromRGBA(r,g,b,1.0)
#define RandomColor                 [UIColor colorWithRed:(arc4random()%256)/256.0 green:(arc4random()%256)/256.0 blue:(arc4random()%256)/256.0 alpha:1];



/**
 *  NSFileManager
 */

#define Document_Path                  [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define APPLICATION_SUPPORT_PATH       [FCFileManager pathForApplicationSupportDirectory]
#define DOCUMENT_APPENDPATH(_path_)    [Document_Path stringByAppendingPathComponent:_path_]
#define APPLICATION_SUPPORT_APPENDPATH(_path_)  [FCFileManager pathForApplicationSupportDirectoryWithPath:_path_]


/**
 *  UIImage
 */
#define LoadBundleImage(A)             [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:A ofType:nil]]
#define ImageNamed(_pointer)           [UIImage imageNamed:[UIUtil imageName:_pointer]]


/**
 *  Notification
 */
#define Notify(_notificationName, _obj, _userInfoDictionary) [[NSNotificationCenter defaultCenter] postNotificationName: _notificationName object: _obj userInfo: _userInfoDictionary];
/**
 */
#define AddObserver(_notificationName, _observer, _observerSelector, _obj) [[NSNotificationCenter defaultCenter] addObserver:_observer selector:@selector(_observerSelector) name:_notificationName object: _obj];

/**
 */
#define removeObserver(_observer) [[NSNotificationCenter defaultCenter] removeObserver: _observer];



/**
 *  NSArray
 */
#define ObjectsArray(...)                       [NSArray arrayWithObjects:__VA_ARGS__, nil]
#define ObjectsMutArray(...)                    [NSMutableArray arrayWithObjects:__VA_ARGS__, nil]
#define  ObjectAtIndex(_array_, _idx_)          (([_array_ isKindOfClass:NSArray.class] && (_idx_<_array_.count)) ? [_array_ objectAtIndex:_idx_] : nil)
#define Valid_Array(arr)                        ((arr) && ([(arr) isKindOfClass:[NSArray class]]) && ([((NSArray *)arr) count] > 0))

/**
 *  NSDictonary
 */
#define ObjectsKeysDict(...)                    [NSDictionary dictionaryWithObjectsAndKeys:__VA_ARGS__, nil]
#define ValueOfDictKey(_dict_,_key_)            ([_dict_ isKindOfClass:NSDictionary.class] ? [_dict_ objectForKey:_key_] : nil)

//保护 安全的获得key所隐射的value
#define ObjectForKey(_dict_, _key_)             ([_dict_ isKindOfClass:NSDictionary.class] ? [_dict_ wk_objectForKeyNotNull:_key_] : nil)

//安全的设置value
#define SetObjectForKeySafely(_dict_, _object_, _key_) \
if(_object_ != nil && _key_!=nil && [_dict_ isKindOfClass:NSDictionary.class]) \
[_dict_ setObject:_object_ forKey:_key_]; \



/**
 *  NSNumber
 */


//NetWork


//NSObject
#define CJAWeakWithNameAndObject(_obj, _name) __weak typeof(_obj) weak##_name = _obj
#define CJAWeak(_obj) CJAWeakWithNameAndObject(_obj, _obj)
#define CJAWeakSelf CJAWeak(self)
#define CJAStrongWithNameAndObject(_obj, _name) __strong typeof(_obj) strong##_name = _obj
#define CJAStrong(_obj) CJAStrongWithNameAndObject(_obj, _obj)
#define CJAStrongSelf CJAStrong(self)

//NSLog
#define LOG_BOOL(object)    (NSLog(@"" #object @" %@", (object ? @"YES" : @"NO") ));
#define LOG_CHAR(object)    (NSLog(@"" #object @" %c", object ));
#define LOG_INT32(object)   (NSLog(@"" #object @" %d", object ));
#define LOG_UINT32(object)  (NSLog(@"" #object @" %u", object ));
#define LOG_LONG(object)    (NSLog(@"" #object @" %ld", object ));
#define LOG_ULONG(object)   (NSLog(@"" #object @" %lu", object ));
#define LOG_INT64(object)   (NSLog(@"" #object @" %qi", object ));
#define LOG_UINT64(object)  (NSLog(@"" #object @" %qu", object ));
#define LOG_FLOAT(object)   (NSLog(@"" #object @" %f",object ));
#define LOG_DOUBLE(object)  (NSLog(@"" #object @" %lf",object ));

// NSInteger and NSInteger are platform independant integer types
#if __LP64__ || (TARGET_OS_EMBEDDED && !TARGET_OS_IPHONE) || TARGET_OS_WIN32 || NS_BUILD_32_LIKE_64
#define LOG_INTEGER(object)     (NSLog(@"" #object @" %ld", object ));
#define LOG_UINTEGER(object)    (NSLog(@"" #object @" %lu", object ));
#else
#define LOG_INTEGER(object)     (NSLog(@"" #object @" %d", object ));
#define LOG_UINTEGER(object)    (NSLog(@"" #object @" %u", object ));
#endif

#define LOG_OBJECT(object)  (NSLog(@"" #object @" %@ %@:%d", [object description], [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__));
#define LOG_KIND_OF_CLASS(object)  (NSLog(@"[" #object @" class] %@", NSStringFromClass([object class])));
#define LOG_METHOD          (NSLog(@"%@ %@:%d\n%@", NSStringFromSelector(_cmd), [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, self))
#define LOG_END_METHOD      (NSLog(@"END %@", NSStringFromSelector(_cmd)))
#define LOG_METHOD_NAME     (NSLog(@"%p %@ %@", self, NSStringFromClass([self class]), NSStringFromSelector(_cmd)))
#define LOG_METHOD_THREAD   (NSLog(@"%@ %@ %@:%d\n%@", NSStringFromSelector(_cmd), [NSThread currentThread], [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, self))
#define LOG_CLASS_METHOD    (NSLog(@"%@ %@", NSStringFromClass([self class]), NSStringFromSelector(_cmd)))

// Profiling Macros
#define START_TIME(tag) NSDate *startTime_ ## tag = [NSDate date];NSLog(@"start           " #tag);
#define CHECK_TIME(tag) NSLog(@"elapsed %0.5f " #tag, [[NSDate date] timeIntervalSinceDate:startTime_ ## tag]);

// NSRange
#define LOG_RANGE(range)    (NSLog(@"" #range @" loc:%u len:%u", range.location, range.length ));
// CGPoint
#define LOG_POINT(point)    (NSLog(@"" #point @" x:%f y:%f", point.x, point.y ));
// CGSize
#define LOG_SIZE(size)      (NSLog(@"" #size @" width:%f height:%f", size.width, size.height ));
// CGRect
#define LOG_RECT(rect)      (NSLog(@"" #rect @" x:%f y:%f w:%f h:%f", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height ));
// CLLocationCoordinate2D
#define LOG_COORD2D(coord)  (NSLog(@"" #coord @" lat,lon: %+.6f,%+.6f",coord.latitude, coord.longitude ));


#define ConvertToLbs(kg)        kg*2.2
#define ConvertToInch(cm)       cm/2.54
#define ConvertToKg(lbs)        lbs/2.2
#define ConvertToCm(inch)       inch*2.54
#define Radians(degrees)        degrees * M_PI / 180
#define Degrees(radians)        radians * 180 / M_PI

#define kMinuteInSeconds        60
#define kHourInSeconds          3600
#define kDayInSeconds           86400
#define kWeekInSeconds          604800

#endif /* Macros_h */











