/* Copyright Urban Airship and Contributors */

#import "UAAction.h"

#define kUAEnableFeatureActionDefaultRegistryName @"enable_feature"
#define kUAEnableFeatureActionDefaultRegistryAlias @"^ef"

/**
 * Argument value to enable user notifications.
 */
extern NSString *const UAEnableUserNotificationsActionValue;

/**
 * Enables an Urban Airship feature.
 *
 * This action is registered under the names enable_feature and ^ef.
 *
 * Expected argument values: 
 * - "user_notifications": To enable user notifications.
 *
 *
 * Valid situations: UASituationForegroundPush, UASituationLaunchedFromPush,
 * UASituationWebViewInvocation, UASituationManualInvocation,
 * UASituationForegroundInteractiveButton, and UASituationAutomation
 *
 * Default predicate: Rejects foreground pushes with visible display options on iOS 10 and above.
 *
 * Result value: Empty.
 */
@interface UAEnableFeatureAction : UAAction


@end


