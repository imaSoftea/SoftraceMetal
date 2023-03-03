//
//  ContentView.swift
//  SoftraceMetal
//
//  Created by Carter Thompson on 3/2/23.
//

import SwiftUI

//Color Schemes
let background_C = Color("Background")
let text_C = Color("Text")
let accent_C = Color("Accent")

struct ContentView: View
{
    @State private var tabSelection = "One"
    
    var body: some View
    {
        VStack()
        {
            TabView(selection: $tabSelection)
            {
                Text("Options")
                    .onTapGesture
                    {
                        tabSelection = "Two"
                    }
                    .tabItem
                    {
                    }
                    .tag("One")
            }
            .frame(width: .infinity , height: 40, alignment: /*@START_MENU_TOKEN@*/.center/*@END_MENU_TOKEN@*/)
            
            // Title
            Text("Rendering Options")
                .padding(30)
                .font(/*@START_MENU_TOKEN@*/.title/*@END_MENU_TOKEN@*/)
                .foregroundColor(text_C)
            
            // Options
            VStack()
            {
                // Primary Shape Settings
                Text("Primary Shape")
                    .foregroundColor(text_C)
                
                HStack()
                {
                    
                }
                
                // Background Shape Settings
                Text("Background Scenery")
                    .foregroundColor(text_C)
                
                HStack()
                {
                    
                }
                
            }
            
        }
        .padding()
        .background(background_C)
        .border(accent_C, width: 3)
    }
}

struct ContentView_Previews: PreviewProvider
{
    static var previews: some View
    {
        Group
        {
            ContentView().environment(\.colorScheme, .dark)
            ContentView().environment(\.colorScheme, .light)
        }
    }
}
