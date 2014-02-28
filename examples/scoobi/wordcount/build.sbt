import AssemblyKeys._

assemblySettings

name := "WordCount"

version := "1.0"

scalaVersion := "2.10.3"

libraryDependencies += "com.nicta" %% "scoobi" % "0.8.0"

resolvers ++= Seq(Resolver.sonatypeRepo("releases"),
                  Resolver.sonatypeRepo("snaspshots"))

mergeStrategy in assembly <<= (mergeStrategy in assembly) { mergeStrategy => {
 case entry => {
   val strategy = mergeStrategy(entry)
   if (strategy == MergeStrategy.deduplicate) MergeStrategy.first
   else strategy
 }
}}