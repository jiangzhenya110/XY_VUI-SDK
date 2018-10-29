//
//  YYBaiduRecognizer.h
//  YYBaiduVoiceSDK
//
//  Created by Chenly on 2018/4/24.
//  Copyright © 2018年 Chenly. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YYBaiduEventManager.h"

typedef NS_ENUM(NSUInteger, YYBaiduRecognizerWorkStatus) {
    YYBaiduRecognizerWorkStatusStartRecognizing,
    YYBaiduRecognizerWorkStatusEndRecognizing,
    YYBaiduRecognizerWorkStatusStartRecording,
    YYBaiduRecognizerWorkStatusEndRecording,
    YYBaiduRecognizerWorkStatusCancel,
    YYBaiduRecognizerWorkStatusError,
    YYBaiduRecognizerWorkStatusLongSpeechEnd,
    YYBaiduRecognizerWorkStatusMeterLevel,
};

extern NSString * YYBaiduRecognizerGetWord(id obj);

@protocol YYBaiduRecognizerDelegate <NSObject>

- (void)YYBaiduRecognizerWorkStatus:(YYBaiduRecognizerWorkStatus)workStatus obj:(id)obj;

@end

@interface YYBaiduRecognizer : NSObject <YYBaiduEventManager>

@property (nonatomic, assign) BOOL hasPunctuation;  // 是否有标点符号，默认:否
@property (nonatomic, weak) id<YYBaiduRecognizerDelegate> delegate;
@property (nonatomic, readonly) BOOL working;

/**
 初始化
  path 、hotPhrasekeys,hotPhraseValues 都可以为空 (hotPhrasekeys,hotPhraseValues 同时存在或不存在)
 @param path 语义路径 baidu_speech_grammar.bsg,带后缀
 @param hotPhrasekeys  热词 key 格式 @{@"domain.intent.object1":@"name1",@"domain.intent.object2":@"name2",@"domain.intent.object3":@"name2"}
 @param hotPhraseValues 热词 Value @{@"name1":@[],@"name2":@[]}
 @return 初始化对象
 */
+ (instancetype)createRecordRecognizerWithPath:(NSString *)path hotPhraseKeys:(NSDictionary *)hotPhrasekeys hotPhraseValues:(NSDictionary *)hotPhraseValues;

- (void)start;
- (void)finish;
- (void)cancel;

@end

@interface YYBaiduRecognizer (AudioFile)

+ (instancetype)createAudioFileRecognizer;

// 格式支持：pcm（不压缩）、wav（不压缩，pcm编码）、amr（压缩格式）；固定16k 采样率；
- (void)recognizerWithAudioFile:(NSString *)filePath completion:(void (^)(BOOL success, id obj))completion;

@end
