//
//  UITableView+WBListKit.h
//  Pods
//
//  Created by Romeo on 2017/5/15.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIkit.h>

@class WBTableViewAdapter;
@class WBTableViewDataSource;
@protocol WBListActionToControllerProtocol;


@interface UITableView (WBListKit)

/**
 取代UITableView的delegate
 增加了从Cell到自定义代理对象的事件传递
 在Cell中合成actionDelegate属性，通过
 actionDelegate属性，将cell的事件传递给View，进而通过这个属性，传递到想传递的地方（通常是控制器）
 */
@property (nonatomic, weak, nullable) id<WBListActionToControllerProtocol> actionDelegate;

/**
 绑定adapter

 @param adapter 'adapter'
 */
- (void)bindAdapter:(nonnull WBTableViewAdapter *)adapter;
- (void)unbindAdapter;

/**
 绑定TableViewSource

 @param source 'source'
 */
- (void)bindViewDataSource:(nonnull WBTableViewDataSource *)source;
- (void)unbindViewDataSource;

@end
