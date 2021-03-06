//
//  UITableView+WBListKit.m
//  Pods
//
//  Created by Romeo on 2017/5/15.
//
//

#import "UITableView+WBListKit.h"
#import "UITableView+WBListKitPrivate.h"
#import <objc/runtime.h>
#import "WBListReusableViewProtocol.h"
#import "WBTableViewAdapterPrivate.h"
#import "WBTableViewDataSource.h"
#import "WBTableViewDataSourcePrivate.h"

static int WBListActionToControllerProtocolKey;

@implementation UITableView (WBListKit)

- (void)setActionDelegate:(id<WBListActionToControllerProtocol>)actionDelegate{
    objc_setAssociatedObject(self, &WBListActionToControllerProtocolKey, actionDelegate, OBJC_ASSOCIATION_ASSIGN);
    self.adapter.actionDelegate = actionDelegate;
}

- (id<WBListActionToControllerProtocol>)actionDelegate{
    return objc_getAssociatedObject(self, &WBListActionToControllerProtocolKey);
}

- (void)bindAdapter:(nonnull WBTableViewAdapter *)adapter{
    [adapter bindTableView:self];
}

- (void)unbindAdapter{
    [self.adapter unBindTableView];
}

- (void)bindViewDataSource:(nonnull WBTableViewDataSource *)source{
    [source bindTableView:self];
}

- (void)unbindViewDataSource{
    [self.source unBindTableView];
}

@end
