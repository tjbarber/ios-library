/* Copyright Urban Airship and Contributors */


#import "UAFetchDeviceInfoAction.h"
#import "UAirship.h"
#import "UAPush.h"
#import "UANamedUser.h"

@implementation UAFetchDeviceInfoAction

NSString *const UAChannelIDKey = @"channel_id";
NSString *const UANamedUserKey = @"named_user";
NSString *const UATagsKey = @"tags";
NSString *const UAPushOptInKey = @"push_opt_in";

- (void)performWithArguments:(UAActionArguments *)arguments
           completionHandler:(UAActionCompletionHandler)completionHandler {
    
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    [dict setValue:[UAirship push].channelID forKey:UAChannelIDKey];
    [dict setValue:[UAirship namedUser].identifier forKey:UANamedUserKey];
    
    NSArray *tags = [[UAirship push] tags];
    if (tags.count) {
        [dict setValue:tags forKey:UATagsKey];
    }

    BOOL optedIn = [UAirship push].authorizedNotificationSettings != 0;
    [dict setValue:@(optedIn) forKey:UAPushOptInKey];
    
    completionHandler([UAActionResult resultWithValue:dict]);
}

@end
