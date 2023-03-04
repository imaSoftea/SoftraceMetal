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
let top_C = Color("Top")

struct ContentView: View
{
    @State private var tabSelection = "One"
    
    var body: some View
    {
        //App Base
        VStack()
        {
            HStack()
            {
                Spacer()
                
                Text("Options")
                .foregroundColor(text_C)
                
                Spacer()
                
                Text("Render")
                    .foregroundColor(text_C)
                
                Spacer()
                
                Text("Export")
                    .foregroundColor(text_C)
                
                Spacer()
                
            }
            .padding(16)
            .frame(maxWidth: .infinity)
            .background(top_C)
            .cornerRadius(10)
            
            // Rendering Options Page
            VStack()
            {
                // Title
                Text("Rendering Options")
                    .padding(30)
                    .font(.system(size: 40))
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
            .frame(maxWidth: .infinity, maxHeight: .infinity)
        }
        .frame(maxWidth: 600, maxHeight: 400)
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
