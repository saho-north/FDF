# 畳み込みニューラルネットワークを用いた半導体の不良ウェハマップの画像認識のプレゼン発表台本

## WHY? (導入)
まずはじめに半導体の製造について説明します。製造過程をスライドに示しました。中でもウエハ検査は、不良が発生した工程や原因の特定に繋がっているため、ウエハ検査の精度向上は、歩留まりの維持、向上につながる重要な工程であることがわかりました。今回は画像認識の技術を用いて、不良ウエハのパターン分類の精度を向上させるアルゴリズムを考えました。チーム全員がpython及び機械学習の初心者であるため、週１回は話し合いを行い、こまめにコミュニケーションを取るよう心がけました。​

## HOW? (手法)
### 畳み込みニューラルネットワーク(CNN)

半導体ウェハマップの画像認識に取り組むにあたって、まずはどのようなアプローチが可能かを調べました。その過程で、畳み込みニューラルネットワーク（CNN）が画像認識において主流の方法として目に留まりました。CNNは、フィルターを利用して画像の局所的な特徴を捉える能力を持ち、これが半導体ウェハマップにおける欠損パターンを特定するのに特に適しているとわかり、CNNを用いてこの課題に取り組むという方向性を決めました。

半導体ウェハマップの画像認識に取り組むにあたって、どのようなアプローチが可能かを調べた結果、畳み込みニューラルネットワーク（CNN）が画像認識において主流の方法として目に留まりました。CNNは、フィルターを利用して画像の局所的な特徴を捉える能力を持ち、この特性が半導体ウェハマップにおける欠損パターンを特定するのに特に適していると判断しました。したがって、この課題にCNNを用いて取り組む方向性を決定しました。


## CNNの課題: Donutの精度が低い

CNNを用いて画像を分類した結果を、混同行列にして出力しました。混同行列とは、スライドの左に示したような、予測されたパターンを横軸に、実際のパターンを縦軸にとった表です。色が濃いほど精度が高いことを表しています。こちらをを確認した結果、Donutと呼ばれるドーナツ状の欠陥パターンをうまく分類できていないことがわかりました。​

## 特徴量抽出でDonutの精度を向上させる

Donut型の分類が難しい理由は、その形状に分類されるものに様々なパターンがあることが要因だと思われます。そこで私たちのグループは、CNNで分類した後、特徴量抽出と呼ばれる方法を用いてDonut型の欠陥を再分類することにしました。特徴量抽出にはいくつかの方法がありますが、今回はウエハーマップをスライドの右の図のようにいくつかの区画に分け、それぞれにどの程度欠落している部分があるかを調べる方法を選択しました。​

## Conclusion (結論)

具体的な結果に移ります。モデルの精度は最大で９０パーセントを越すことができました。また高い確率で８０パーセントを越すことができています。ドーナツに分類される画像に対策できたことが本当に安定性に響いています。​

できることはすべて全力で取り組んできました。是非私たちの結果を見ていただけると嬉しいです。​