name := "funset"

version := "0.1"

scalaVersion := "2.12.8"

scalacOptions ++= Seq("-deprecation")

// grading libraries
libraryDependencies += "junit" % "junit" % "4.10" % "test"

// for funsets
libraryDependencies += "org.scala-lang.modules" %% "scala-parser-combinators" % "1.0.4"

//scala test
libraryDependencies += "org.scalactic" %% "scalactic" % "3.0.5"
libraryDependencies += "org.scalatest" %% "scalatest" % "3.0.5" % "test"
