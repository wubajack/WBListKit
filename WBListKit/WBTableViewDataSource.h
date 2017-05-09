//
//  WBTableViewDataSource.h
//  WBListKit
//
//  Created by fangyuxi on 2017/3/29.
//  Copyright © 2017年 xcoder.fang@gmail.com. All rights reserved.
//

#import "WBListDataSource.h"
#import "WBTableViewAdapter.h"

/**
 for UITableView
 */
@interface WBTableViewDataSource : WBListDataSource

/**
 WBTableViewDataSource会自动创建一个适合于UITableView的Adapter,当数据加载完毕后
 我们可以通过这个adapter将数据交给UITableView
 */
@property (nonatomic, strong, readonly, nullable) WBTableViewAdapter *tableViewAdapter;

/**
 绑定tableView
 当DataSource和TableView出现多对一情况的时候
 在使用指定的DataSource之前，需要重新绑定
 @param tableView 'tableView'
 */
- (void)bindTableView:(nullable UITableView *)tableView;
- (void)unBindTableView;

@end