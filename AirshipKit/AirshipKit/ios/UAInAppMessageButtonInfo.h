/* Copyright 2018 Urban Airship and Contributors */

#import <UIKit/UIKit.h>
#import "UAInAppMessageTextInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Button behavior.
 */
typedef NS_ENUM(NSInteger, UAInAppMessageButtonInfoBehaviorType) {
    /**
     * Dismiss behavior
     */
    UAInAppMessageButtonInfoBehaviorDismiss,
    
    /**
     * Cancel behavior
     */
    UAInAppMessageButtonInfoBehaviorCancel,
    
};

/**
 * Button identifier limit (100 characters).
 */
extern NSUInteger const UAInAppMessageButtonInfoIDLimit;


/**
 * Builder class for UAInAppMessageButtonInfo.
 */
@interface UAInAppMessageButtonInfoBuilder : NSObject

/**
 * Button label.
 *
 * Required
 */
@property(nonatomic, strong, nullable) UAInAppMessageTextInfo *label;

/**
 * Button identifier.
 *
 * Required. Must be between [1-100] characters.
 */
@property(nonatomic, copy, nullable) NSString *identifier;

/**
 * Button tap behavior.
 *
 * Optional. Defaults to UAInAppMessageButtonInfoBehaviorDismiss.
 */
@property(nonatomic, assign) UAInAppMessageButtonInfoBehaviorType behavior;

/**
 * Button border radius.
 *
 * Optional. Defaults to 0.
 */
@property(nonatomic, assign) NSUInteger borderRadius;

/**
 * Button background color.
 *
 * Optional. Defaults to transparent.
 */
@property(nonatomic, strong) UIColor *backgroundColor;

/**
 * Button border color.
 *
 * Optional. Defaults to transparent.
 */
@property(nonatomic, strong) UIColor *borderColor;

/**
 * Button actions.
 *
 * Optional.
 */
@property(nonatomic, copy, nullable) NSDictionary *actions;

/**
 * Checks if the builder is valid and will produce a text info instance.
 * @return YES if the builder is valid (requires label and id), otherwise NO.
 */
- (BOOL)isValid;

@end


/**
 * Defines an in-app message button.
 *
 * @note This object is built using `UAInAppMessageButtonInfoBuilder`.
 */
@interface UAInAppMessageButtonInfo : NSObject

/**
 * Button label.
 */
@property(nonatomic, readonly) UAInAppMessageTextInfo *label;

/**
 * Button identifier.
 */
@property(nonatomic, readonly) NSString *identifier;

/**
 * Button tap behavior.
 */
@property(nonatomic, readonly) UAInAppMessageButtonInfoBehaviorType behavior;

/**
 * Button border radius.
 */
@property(nonatomic, readonly) NSUInteger borderRadius;

/**
 * Button background color.
 */
@property(nonatomic, readonly) UIColor *backgroundColor;

/**
 * Button border color.
 */
@property(nonatomic, readonly) UIColor *borderColor;

/**
 * Button actions.
 */
@property(nonatomic, nullable, readonly) NSDictionary *actions;

/**
 * Creates an in-app message button info with a builder block.
 *
 * @return The in-app message button info if the builder sucessfully built it, otherwise nil.
 */
+ (nullable instancetype)buttonInfoWithBuilderBlock:(void(^)(UAInAppMessageButtonInfoBuilder *builder))builderBlock;

/**
 * Extends an in-app message button info with a builder block.
 *
 * @param builderBlock The builder block.
 * @return An extended instance of UAInAppMessageButtonInfo.
 */
- (nullable UAInAppMessageButtonInfo *)extend:(void(^)(UAInAppMessageButtonInfoBuilder *builder))builderBlock;

@end

NS_ASSUME_NONNULL_END

